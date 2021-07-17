/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

*/


/*
解题思路：滑动窗口

- 先扫描一遍 T，把对应的字符及其出现的次数存到 HashMap 中。

- 然后开始遍历S，就把遍历到的字母对应的 HashMap 中的 value 减一，如果减1后仍大于等于0，cnt 自增1。

- 如果 cnt 等于T串长度
    开始循环，纪录一个字串并更新最小字串值。然后将子窗口的左边界向右移，
    如果某个移除掉的字母是T串中不可缺少的字母，那么 cnt 自减1，表示此时T串并没有完全匹配。

 
    需要注意的是，S中不在T的元素 在hashmap先--再++，始终还是 <= 0，并且最重归零。
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];          //遍历t
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;    //--letterCnt[s[i]] >= 0，s[i]在t中
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen); //从left开始，长度为minLen的字符串
                }
                if (++letterCnt[s[left]] > 0) --cnt;   //收缩左边界++letterCnt[s[left]] > 0， 0->1 该元素在t中，
                //因为不在t中的本来为0，先减去，现在再增加，最终还是0.
                ++left;
            }
        }
        return res;

    }
};