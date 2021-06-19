/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

限制：

0 <= 节点个数 <= 5000
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
class Solution {
private:
    TreeNode* traveral(vector<int>& preorder, vector<int>& inorder){

        //1.如果数组大小为零，返回NULL
        if(preorder.size()==0) return NULL;

        //2.取前序数组的第一个元素为root根节点
        int rootval=preorder[0];
        TreeNode* root = new TreeNode(rootval);

        //3.根据root切割中序数组为 中序左数组、中序右数组
        int k; //分割点
        for(k=0;k<inorder.size();++k){
            if(inorder[k]==rootval)
                break;
        }
        vector<int> inleft(inorder.begin(),inorder.begin()+k); // [0,k)
        vector<int> inright(inorder.begin()+k+1,inorder.end());// [k+1,end)
        //4.根据中序左数组长度切割前序数组为 前序左数组、前序右数组
        preorder.erase(preorder.begin());//删除根节点，更新前序数组
        vector<int> preleft(preorder.begin(),preorder.begin()+inleft.size());  //[0,inleft.size())
        vector<int> preright(preorder.begin()+inleft.size(),preorder.end());   //[inleft.size(),end)
        //5.递归处理 左区间和右区间
        root->left=traveral(preleft,inleft);
        root->right=traveral(preright,inright);
        return root;

    }  
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)  return NULL;
        return traveral(preorder,inorder);

    }
};



class Solution {
private:
    unordered_map<int, int> mp;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preleft, int preright, int inleft, int inright) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preleft;
        // 在中序遍历中定位根节点
        int inorder_root = mp[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inleft;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preleft + 1, preleft + size_left_subtree, inleft, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preleft + size_left_subtree + 1, preright, inorder_root + 1, inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            mp[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
