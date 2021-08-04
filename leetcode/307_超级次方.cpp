/*
 * @Author: Henry
 * @Date: 2021-08-04 21:43:50
 * @LastEditTime: 2021-08-04 21:59:05
 * @Description: 
 */


/*
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
 

提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0

*/

/**
 * 递归
 */
class Solution {
private:
    int mod = 1337;
    //求 a 的 k 次方， 对 mod 取余
    int modPow(int a, int k){
        a %= mod;
        int res = 1;
        for (int i = 0; i < k; ++i){
            res *= a;
            res %= mod;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0)  return 1;
        int last = b.back();
        b.pop_back();
        // 将原问题化简，缩小规模递归求解
        int part1 = modPow(a, last);
        int part2 = modPow(superPow(a, b), 10);
        // 合并出结果
        return (part1 * part2)%mod;
        // return (modPow(a, last) * modPow(superPow(a, b), 10)) % mod;
    }
};

/**
 * 快速幂
 */
class Solution {
private:
    int mod = 1337;
    int modPow(int a, int k){
        
        if (k == 0) return 1;
        a %= mod;
        // k 是奇数
        if (k % 2 == 1)  return (a * modPow(a, k - 1)) % mod;
        else {// k 是偶数
            int sub = modPow(a, k / 2);
            return (sub * sub) % mod;
        }
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0)  return 1;
        int last = b.back();
        b.pop_back();
        // 将原问题化简，缩小规模递归求解
        int part1 = modPow(a, last);
        int part2 = modPow(superPow(a, b), 10);
        // 合并出结果
        return (part1 * part2)%mod;
        // return (modPow(a, last) * modPow(superPow(a, b), 10)) % mod;
    }
};


