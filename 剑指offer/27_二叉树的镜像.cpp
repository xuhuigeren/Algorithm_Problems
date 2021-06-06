/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

*/
//递归法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right); // 中
        invertTree(root->left); // 左
        invertTree(root->right); // 右
        return root;
    }
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};


//辅助栈
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        //辅助栈
        if(root==NULL) return root;

        stack<TreeNode *> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if(node->left!=NULL) st.push(node->left);
            if(node->right!=NULL) st.push(node->right);
            swap(node->left,node->right);

        }
        return root;

    }
};
