/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10


*/

class Solution {
    vector<vector <int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!used[i]){
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1])  continue; // 去重
                path.push_back(nums[i]);
                used[i]=true;
                backtrack(nums,used);
                used[i]=false;
                path.pop_back();
                
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<int> path;
        res.clear();
        path.clear();
        vector<bool> used(nums.size(),0);
        sort(nums.begin(), nums.end());
        backtrack(nums,used);
        return res;
    }
};