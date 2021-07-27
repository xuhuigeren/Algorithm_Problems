/*
 * @Author: Henry
 * @Date: 2021-07-26 22:21:24
 * @LastEditTime: 2021-07-27 19:42:28
 * @Description: 
 */

/*
给定一个字符串 AA, 长度为 NN，1 \leq N \leq 2*10^51≤N≤2∗10 
5
 ，下标从 00 开始标号，仅包含 00 到 99 这十种字符。

再给定另一个字符串 BB，长度为 MM，1 \leq M \leq 2*10^51≤M≤2∗10 
5
 ，下标从 00 开始标号，也是仅包含 00 到 99 这十种字符。

例如以下字符串就是一个合法的 AA 或 BB:

066465353473034515
现在我们要在 AA 寻找一个连续的子串 ss，使得 ss 包含 BB 中出现的所有字符，且要保证 ss 的长度尽可能短。如果存在多个符合上述条件的 ss，返回最靠左的那个。

例如:

BB 串：
3314
AA 串：
563145633
子串 A[2:7]A[2:7] 为 314563，包含了 BB 串中出现的 3, 3, 1, 4。

子串 A[3:8]A[3:8] 为 145633，也包含了 BB 串中出现的 3, 3, 1, 4。

两个子串长度一样，而前者更靠左，因此前者就是我们要找的答案。

输入
每组测试数据的第一行是整数 TT，1 \leq T \leq 10001≤T≤1000，表示接下来有 TT 对 A, BA,B 串
接下来有 2*T2∗T 行，每两行分别表示一对 AA 串和 BB 串
AA 串长度为 NN，1 \leq N \leq 2*10^51≤N≤2∗10 
5
 
BB 串长度为 MM，1 \leq M \leq 2*10^51≤M≤2∗10 
5
 
一组测试数据中字符总数为 CC，2*T \leq C \leq 10^62∗T≤C≤10 
6
 
输出
输出 TT 行，每行两个整数，用空格分割，表示 AA 的子串下标
如果不存在这样的合法子串，输出 -1 -1
样例 1
输入
1
563145633
3314
输出
2 7
样例 2
输入
2
678
123
12345
1233
输出
-1 -1
-1 -1
*/




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s, t;
    vector<vector<int>> res;
    void minWindow() {
        cin >> s >> t;
        unordered_map<char, int> mp;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++mp[c];        
        for (int i = 0; i < s.size(); ++i) {
            if (--mp[s[i]] >= 0) ++cnt;   
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res.clear();
                    res.push_back({left,left+minLen-1});
                }
                if (++mp[s[left]] > 0) --cnt;   
                ++left;
            }
        }
        // return res;
        if(res.size()==0)
            cout<< -1 << " " << -1 <<endl;
        else
            cout << res[0][0] << " "  << res[0][1] <<endl;
    }
};
int main(){
    int T;
    cin >> T;
    while(T--) Solution().minWindow();
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

string s, t;
unordered_map<char, int> mp;
void solve(){
    cin >> s >> t;
    vector<vector<int>> res;
    int left = 0, cnt = 0, minLen = INT_MAX;
    mp.clear();
    for (char c : t) ++mp[c];         
    for (int i = 0; i < s.size(); ++i) {
        if (--mp[s[i]] >= 0) ++cnt;   
        while (cnt == t.size()) {
            if (minLen > i - left + 1) {
                minLen = i - left + 1;
                res.clear();
                res.push_back({left,left+minLen-1});
            }
            if (++mp[s[left]] > 0) --cnt;   
            ++left;
        }
    }
    // return res;
    if(res.size()==0)
        cout<< -1 << " " << -1 <<endl;
    else
        cout << res[0][0] << " "  << res[0][1] <<endl;
}

int main(){
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
