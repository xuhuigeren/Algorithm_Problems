/*
 * @Author: Henry
 * @Date: 2021-06-12 16:50:03
 * @LastEditTime: 2021-07-28 21:59:32
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
