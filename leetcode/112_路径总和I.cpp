/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。


示例 1：          5
                /  \   
               4    8
              /     / \
            11     13  4
           /  \       / \
          7    2     5   1



输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：true

示例 2：
                 1
                / \   
               2   3

输入：root = [1,2,3], targetSum = 5
输出：false
示例 3：

输入：root = [1,2], targetSum = 0
输出：false
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //递归
        if(!root)  return false;  //根节点为空
        if(!root->left && !root->right)  return targetSum==root->val;  //只有根节点

        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);


    }

};