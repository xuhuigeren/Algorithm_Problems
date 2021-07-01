/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字
要求时间复杂度是O(n)，空间复杂度是O(1)。

 
示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000

*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;++i){
            if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1])
                res.push_back(nums[i]);
        }
        if(nums[0]!=nums[1]) res.push_back(nums[0]);
        if(nums[nums.size()-1]!=nums[nums.size()-2]) res.push_back(nums[nums.size()-1]);

        return res;



    }
};

由于数组中存在着两个数字不重复的情况，我们将所有的数字异或操作起来，最终得到的结果是这两个数字的异或结果：
(相同的两个数字相互异或，值为0)) 最后结果一定不为0，因为有两个数字不重复。

演示：

4 ^ 1 ^ 4 ^ 6 => 1 ^ 6

6 对应的二进制： 110
1 对应的二进制： 001
1 ^ 6  二进制： 111

此时我们无法通过 111（二进制），去获得 110 和 001。
那么当我们可以把数组分为两组进行异或，那么就可以知道是哪两个数字不同了。
我们可以想一下如何分组：

重复的数字进行分组，很简单，只需要有一个统一的规则，就可以把相同的数字分到同一组了。例如：奇偶分组。因为重复的数字，数值都是一样的，所以一定会分到同一组！
此时的难点在于，对两个不同数字的分组。
此时我们要找到一个操作，让两个数字进行这个操作后，分为两组。
我们最容易想到的就是 & 1 操作， 当我们对奇偶分组时，容易地想到 & 1，即用于判断最后一位二进制是否为 1。来辨别奇偶。
你看，通过 & 运算来判断一位数字不同即可分为两组，那么我们随便两个不同的数字至少也有一位不同吧！
我们只需要找出那位不同的数字mask，即可完成分组（ & mask ）操作。

由于两个数异或的结果就是两个数数位不同结果的直观表现，所以我们可以通过异或后的结果去找 mask！
所有的可行 mask 个数，都与异或后1的位数有关。


num1:       101110      110     1111
num2:       111110      001     1001
num1^num2:  010000      111     0110

可行的mask:  010000      001     0010
                        010     0100
                        100     
为了操作方便，我们只去找最低位的mask:


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

