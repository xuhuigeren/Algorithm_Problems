/*
题目描述：
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，
因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3

示例 2：

输入：m = 3, n = 1, k = 0
输出：1

提示：

1 <= n,m <= 100
0 <= k <= 20

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int res=0;
    //计算数位相加
    int sumdigt(int x){
        int sum = 0;
        while(x){
            sum += x%10;  //个位
            x = x/10;
        }
        return sum;
    }
    // DFS+visited数组
    void dfs(vector<vector<bool>> &visited, int x, int y, int m, int n, int k ){
        if(x<0||y<0||x>=m||y>=n||(sumdigt(x)+sumdigt(y))>k||visited[x][y]==1)  return;
        res++;
        visited[x][y] = true;
        dfs(visited,x+1,y,m,n,k);
        dfs(visited,x-1,y,m,n,k);
        dfs(visited,x,y+1,m,n,k);
        dfs(visited,x,y-1,m,n,k);
        
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        dfs(visited,0,0,m,n,k);
        return res;
    }
};

int main(){
    int a = Solution().movingCount(3,2,3);
    cout<< Solution().sumdigt(35)+Solution().sumdigt(38) <<endl;
    cout<< a <<endl;
}