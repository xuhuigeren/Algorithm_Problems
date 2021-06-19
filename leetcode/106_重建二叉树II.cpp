/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

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
private:
    TreeNode* traveral(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size()==0)  return NULL;
        int rootval=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootval);
        // if(inorder.size()==1)  return root;
        int k;
        for(k=0;k<inorder.size();++k){
            if(inorder[k]==rootval)
                break;
        }
        vector<int> inleft(inorder.begin(),inorder.begin()+k);
        vector<int> inright(inorder.begin()+k+1,inorder.end());
        postorder.erase(postorder.end()-1);
        vector<int> postleft(postorder.begin(),postorder.begin()+inleft.size());
        vector<int> postright(postorder.begin()+inleft.size(),postorder.end());

        root->left=traveral(inleft,postleft);
        root->right=traveral(inright,postright);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0)  return NULL;

        return traveral(inorder,postorder);

    }
};