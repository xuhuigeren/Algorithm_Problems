/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000
1 <= nums[i] <= 10000

*/

//方法一
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //首尾双指针
        int left=0, right=nums.size()-1;
        while(left<right){
            if((nums[left]&1)==1){
                left++;
                continue;
            }
            if((nums[right]&1)==0){
                right--;
                continue;
            }
            swap(nums[left++],nums[right--]);
        }
        return nums;

    }
};


//自定义排序
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
       sort(nums.begin(),nums.end(),[](int a,int b){return a%2>b%2;});
       return nums;
    }
};
