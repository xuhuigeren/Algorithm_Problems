/*从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回一：

[3,9,20,15,7]
 
返回二：
[
  [3],
  [9,20],
  [15,7]
]

返回三：
[
  [3],
  [20,9],
  [15,7]
]
提示：

节点总数 <= 1000

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
（一）
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //迭代
        vector<int> res;
        queue<TreeNode *> st;
        if(!root)  return res;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.front();            //中
            st.pop();
            res.push_back(node->val);
            if(node->left)  st.push(node->left);    //左
            if(node->right) st.push(node->right);   //右
            
        }
        return res;
    }
};



（二）
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        if(root)  qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            vector<int> vec;
            for(int i=0;i<n;++i){
                TreeNode* node=qu.front();
                qu.pop();
                vec.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};

（三）
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        if(root)  qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            vector<int> vec;
            for(int i=0;i<n;++i){
                TreeNode* node=qu.front();
                qu.pop();
                vec.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            res.push_back(vec);
        }
        int len = res.size();
        for(int i=0;i<len;++i){
            if(i%2==1) reverse(res[i].begin(),res[i].end());
        }
        return res;

    }
};