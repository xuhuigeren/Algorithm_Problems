/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

*/

遍历字符串，出现一次，值为true，再次出现，值为false

再次遍历字符串，返回第一个true

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> mp;
        for(auto x:s){
            mp[x]=mp.find(x)==mp.end();
        }
        for(auto x:s){
            if(mp[x])
                return x;
        }     
        return ' ';
    }
};