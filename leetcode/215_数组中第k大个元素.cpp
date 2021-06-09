/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

*/

class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};



//快速排序！！
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int partition(vector<int> &nums, int left, int right){
        int i=left, j=right;
        //随机选择
        int rd = rand()%(right-left+1)+left;
        swap(nums[rd], nums[right]);

        while(i<j){
            while(i<j && nums[i]>=nums[right]) i++;
            while(i<j && nums[j]<=nums[right]) j--;
            swap(nums[i], nums[j]);
        }
        swap(nums[i],nums[right]);
        return i;
        
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;       
        while (true)
        {
            int t = partition(nums,left,right);
            if(t==k-1)  return nums[t];
            if(t<k-1)   left=t+1;
            if(t>k-1)   right=t-1;
        }      
        return nums[k-1];
       
    }
};

int main(){

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(9);
    // arr.push_back(99);
    // arr.push_back(99);
    // arr.push_back(99);

    int k = 8 ;
    int res = Solution().findKthLargest(arr,k);
    cout<< res<<endl;

}