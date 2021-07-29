/*
 * @Author: Henry
 * @Date: 2021-06-12 16:50:03
 * @LastEditTime: 2021-07-29 20:34:00
 * @Description: 
 */
/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 
提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

*/

/**
 * <中心扩展法>
 * 由于回文串的长度可奇可偶，比如 “bob” 是奇数形式的回文，”noon” 就是偶数形式的回文，
 * 两种形式的回文都要搜索，对于奇数形式的，我们就从遍历到的位置为中心，向两边进行扩散，
 * 对于偶数情况，我们就把当前位置和下一个位置当作偶数行回文的最中间两个字符，然后向两边进行搜索
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len < 2)
            return s;
        int start=0;    //记录回文子串起始位置
        int end=0;      //记录回文子串终止位置
        int mlen=0;     //记录最大回文子串的长度
        for(int i=0;i<len;i++){
            int len1=expendaroundcenter(s,i,i);     //一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);   //两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1){
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
    }
private:
    int expendaroundcenter(string s,int left,int right){
        //计算以left和right为中心的回文串长度
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L]){
            L--;
            R++;
        }
        return R-L-1;
    }
};



/**
 * 动态规划
 * 1.确定dp数组（dp table）以及下标的含义
 * 2.确定递推公式
 * 3.dp数组如何初始化
 * 4.确定遍历顺序
 * 
 * 在确定递推公式时，就要分析如下几种情况。
 * 整体上是两种，就是s[i]与s[j]相等，s[i]与s[j]不相等这两种。
 * 当s[i]与s[j]不相等，那没啥好说的了，dp[i][j]一定是false。
 * 当s[i]与s[j]相等时，这就复杂一些了，又有如下三种情况
 *  情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
 *  情况二：下标i 与 j相差为1，例如aa，也是回文子串
 *  情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，
 *  我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，
 *  这个区间是不是回文就看dp[i + 1][j - 1]是否为true。
 * 
 *     —— —— —— ——   —— —— —— ——
 *    |            |            |
 *    |            |  dp[i][j]  |
 *    |            |            |
 *    |            |            |
 *     —— —— —— ——  —— —— —— ——
 *    |            |            |
 *    |dp[i+1][j-1]|            |
 *    |            |            |
 *    |            |            |
 *     —— —— —— ——   —— —— —— ——
 */
class Solution {
public:
    string longestPalindrome(string s) {
        // 布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，
        // 如果是dp[i][j]为true，否则为false。
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int maxlenth = 0;
        int left = 0;
        int right = 0;
        // dp[i][j]由dp[i+1][j-1]确定，因此从左下向右上遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {    // 情况一 和 情况二
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j] && j - i + 1 > maxlenth) {
                    maxlenth = j - i + 1;
                    left = i;
                    right = j;
                }
            }

        }
        return s.substr(left, right - left + 1);
    }
};


// 以上代码是为了凸显情况一二三，当然是可以简洁一下的
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int maxlenth = 0;
        int left = 0;
        int right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
                if (dp[i][j] && j - i + 1 > maxlenth) {
                    maxlenth = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, maxlenth);
    }
};
