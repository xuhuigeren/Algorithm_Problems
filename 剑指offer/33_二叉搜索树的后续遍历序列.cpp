/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
 

提示：

数组长度 <= 1000

*/

/*【left,k-1】< right < 【k,right-1】，

            right
            /   \
           /     \ 
    left,k-1    k,right-1


*/ 


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder,0,postorder.size()-1);

    }

    bool dfs(vector<int>& nums, int left, int right){
        if(left>=right) return true;   // >=  见下方
        // int root=nums[right];
        int k=left;
        while(k<right && nums[k]<nums[right])  k++;
        for(int i=k;i<right;++i){
            if(nums[i]<nums[right]){
                return false;
            }
        }
        return dfs(nums,left,k-1) && dfs(nums,k,right-1);//【left,k-1】， 【k,right-1】，right
    }
};


/*
关于 第47行
当数组为 【12，14，16，10】时
     10
       \
       16
       /
     14
     /
   12

第一趟 return dfs(nums,left,left-1) && dfs(nums,left,right-1)

*/ 