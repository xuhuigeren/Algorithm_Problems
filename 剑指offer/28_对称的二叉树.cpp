/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
 

限制：
0 <= 节点个数 <= 1000

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归求解
class Solution {
public:

    bool compare(TreeNode *left, TreeNode *right){
        if(left==nullptr && right!=nullptr) return false;
        else if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val!=right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);

        return outside&&inside;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;

        return compare(root->left,root->right);

    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        queue<TreeNode *> qu;
        qu.push(root->left);
        qu.push(root->right);
        while(!qu.empty()){
            TreeNode *leftnode = qu.front();  qu.pop();
            TreeNode *rightnode = qu.front(); qu.pop();
            //左右节点为空，对称
            if(!leftnode&&!rightnode) continue;
            //左右节点有一个不为空，或者都不为空但值不相等，返回false
            if (!leftnode || !rightnode || (leftnode->val != rightnode->val)) return false;

            qu.push(leftnode->left);
            qu.push(rightnode->right);
            qu.push(leftnode->right);
            qu.push(rightnode->left);
            

        }
        return true;

    }
};