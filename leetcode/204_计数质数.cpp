/*
 * @Author: Henry
 * @Date: 2021-08-04 21:22:13
 * @LastEditTime: 2021-08-04 21:27:26
 * @Description: Eratosthenes筛选法
 */

/**
 * Eratosthenes筛选法
 * 从2开始遍历到n
 * i=2,并排除2的倍数
 * i=3,并排除3的倍数
 * i=5,并排除5的倍数
 * 。。。
 */
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        //初始默认所有数为质数
        vector<bool> res(n, true);
        for (int i = 2; i < n; i++) {
            if (res[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    //排除i的倍数
                    res[j] = false;
                }
            }
        }
        return count;
    }
};