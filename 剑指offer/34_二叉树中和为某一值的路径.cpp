/*  
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：          5
                /  \   
               4    8
              /     / \
            11     13  4
           /  \       / \
          7    2     5   1



输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：
                 1
                / \   
               2   3

输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 

提示：

树中节点总数在范围 [0, 10000] 内


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector <int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,target);
        return res;
    }

    void dfs(TreeNode* root, int target){
        //edge case
        if(!root)  return;
        path.push_back(root->val);
        target=target- root->val;
        
        //递归终止条件
        if(!root->left && !root->right && target==0){
            res.push_back(path);
        }
        //递归
        dfs(root->left,target);
        dfs(root->right,target);
        //回溯
        path.pop_back();
    }
};