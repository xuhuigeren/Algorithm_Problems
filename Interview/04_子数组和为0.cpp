/*
给定一个数组，返回一个和为0的子数组，若不存在，返回NULL。分析时间与空间复杂度。

示例：
输入：
4，2，-5，1，2，-3
输出：
2，-5，1，2

*/
#include<bits/stdc++.h>
using namespace std;

//枚举
// vector<vector <int>> subarr(vector<int> &nums, int k){
//     vector<vector <int>> res;
//     vector<int> sub;
//     for(int i=0;i<nums.size();++i){
//         int sum=0;
//         sub.clear();
//         for(int j=i;j<nums.size();++j){
//             sub.push_back(nums[j]);
//             sum=accumulate(sub.begin(),sub.end(),0);//求和
//             if(sum==k) 
//                 res.push_back(sub);
//         }
//     }
//     return res;
// }
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
/*
sum[i]=sum[i-1]+nums[i]
sum[i]=sum[j-1]+{nums[j]+....+nums[i]}
令nums[j]+....+nums[i]=k
sum[i]-k=sum[j-1]
判断是否存在这样的 j
即遍历前n个元素，在前缀和中判断是否存在这样的sum[j-1],及其个数
*/


int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;++i){
        cin>> arr[i];
    }
    int res;
    res = subarraySum0(arr, 0);
    cout<<res<<endl;
    
    // for(auto it=res.begin();it!=res.end();++it){
    //     for(int i=0;i<(*it).size();++i){
    //         cout<<(*it)[i]<<" ";
    //     }
    //     cout<<endl;
    // }
}
