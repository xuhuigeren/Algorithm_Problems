/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31

*/


class Solution {
    //reference to non-static member function must be called===》加上static
    static bool cmp_value(const pair<int, int> left,const pair<int,int> right){
        return left.second < right.second;
    }
public:
    
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
       
        auto i= min_element(mp.begin(),mp.end(),cmp_value);
        return i->first;

    }
};