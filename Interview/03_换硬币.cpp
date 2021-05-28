/*
描述
给出不同面额的硬币以及一个总金额. 写一个方法来计算给出的总金额可以换取的最少的硬币数量. 
如果已有硬币的任意组合均无法与总金额面额相等, 那么返回 -1.

你可以假设每种硬币均有无数个 总金额不会超过10000 硬币的种类数不会超过500, 每种硬币的面额不会超过100

样例1                                      样例2
输入：                                      输入：
[1, 2, 5]                                  [2]
11                                          3
输出： 3                                    输出： -1
解释： 11 = 5 + 5 + 1                       

*/



class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &a, int k) {
    
        vector<int> f(k+1);
        int n=a.size();
        //base case
        f[0]=0;

        const int INF = 0x3f3f3f3f; //INT_MAX;

        for(int i=1;i<=k;++i){
            f[i]=INF;
            for(int j=0;j<n;++j){
                //转移方程
                if(i>=a[j]&&f[i-a[j]!=INF]){
                    f[i]=min(f[i-a[j]]+1,f[i]);
                }
            }
        }
        if(f[k]==INF){
            f[k]=-1;
        }
        return f[k];
    }
};

//时间复杂度： O(k*n)