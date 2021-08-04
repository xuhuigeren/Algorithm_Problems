/*
 * @Author: Henry
 * @Date: 2021-08-04 21:22:13
 * @LastEditTime: 2021-08-04 21:42:56
 * @Description: Eratosthenes筛选法
 */

/*
统计所有小于非负整数 n 的质数的数量。

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
 

提示：

0 <= n <= 5 * 106

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