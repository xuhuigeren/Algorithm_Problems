/*
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8


*/

class Solution {
    vector<string> res;
public:
 void backtrack(string &s,string& path,vector<bool>& used){
        if(path.size()==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(!used[i]){
                /*当i可以选第一个元素之后的元素时(因为如果i=0，即只有一个元素
                哪来的重复？有重复即说明起码有两个元素或以上,i>0)，然后判断当前元素是否和上一个元素相同？
                如果相同，再判断上一个元素是否能用？如果三个条件都满足，那么该分支一定是重复的，应该剪去*/

                if(i>=1&&s[i-1]==s[i]&&!used[i-1])//判重剪枝
                    continue;
                path.push_back(s[i]);
                used[i]=true;
                backtrack(s,path,used);
                used[i]=false;
                path.pop_back();
            }   
        }
    }

vector<string> permutation(string s) {
        if(s.size()==0)
            return{};
        string temp="";
        sort(s.begin(),s.end());
        vector<bool>used(s.size());
        backtrack(s,temp,used);
        return res;
    }
};