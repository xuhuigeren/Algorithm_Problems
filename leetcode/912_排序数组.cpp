/*
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

*/

class Solution {
    //快速排序
    int partition(vector<int>& nums, int left, int right){
        int i=left, j=right;
        //s随机选择pivot元素
        int rd = rand()%(right-left+1)+left; 
        swap(nums[rd], nums[right]);
        //从小到大排序
        while(i<j){
            while(i<j && nums[i]<=nums[right]) i++;
            while(i<j && nums[j]>=nums[right]) j--;
            swap(nums[i], nums[j]);
        }
        swap(nums[i],nums[right]);
        return i;
    }

    
    void quicksort(vector<int>&nums, int l, int r){
        if(l<r){
            int pos = partition(nums,l,r);
            quicksort(nums,l,pos-1);
            quicksort(nums,pos+1,r);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quicksort(nums,0,(int)nums.size()-1);
        return nums;
        
    }
};