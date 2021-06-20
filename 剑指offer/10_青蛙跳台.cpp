/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1
提示：

0 <= n <= 100

*/

class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;

        vector<int> dp(n+1);
        //base case
        dp[0]=1,dp[1]=1;

        for(int i=2;i<=n;++i){
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];

    }
};


class Solution {
public:
    int numWays(int n) {
        // if (n == 0 || n == 1) return 1;

        
        //base case
        int a=1, b=1, sum;

        for(int i=0;i<n;++i){
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        return a;

    }
};