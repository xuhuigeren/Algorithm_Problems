/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

*/


class Solution {
public:
    //枚举
    int subarraySum0(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }


    //hashmap
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> m;
        int sum = 0;
        m[0] = 1;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            // if(m.find(sum - k)!=m.end())   //find()通过给定主键查找元素,没找到则返回unordered_map::end
            if(m.count(sum-k)) //cout()返回0或者1
                res += m[sum - k];  
            m[sum]++;
        }
        return res;
    }
};

/*
sum[i]=sum[i-1]+nums[i]
sum[i]=sum[j-1]+{nums[j]+....+nums[i]}
令nums[j]+....+nums[i]=k
sum[i]-k=sum[j-1]
判断是否存在这样的 j
即遍历前n个元素，在前缀和中判断是否存在这样的sum[j-1],极其个数
*/