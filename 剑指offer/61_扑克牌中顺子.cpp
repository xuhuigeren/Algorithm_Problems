/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，
而大、小王为 0 ，可以看成任意数字。A 不能视为 14。


示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .

*/

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> s;  //set是有序的，不用单独求最大最小
        for(int i:nums){
            if(s.find(i)!=s.end())  //表示 i 在set中
                return 0;
            if(i)
                s.insert(i);
        }
        return *--s.end()-*s.begin()<5;  //rbegin() 指向容器最后一个元素


    }
};