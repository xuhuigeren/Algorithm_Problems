/*
2021-05-27 携程测试
n坛酒只有1坛有毒，用公鸡🐓试毒，试毒时间minuteDie，给定时间minuteAll
输入：
n坛酒，观察时间minuteDie，总时间minuteAll

输出：
规定时间内找出有毒酒的最少公鸡数
*/

//结论：  n 个公鸡， t 次实验， 可以从 (t+1)^n 坛酒中检验出毒药。

#include<bits/stdc++.h>
using namespace std;

int findPoisonWine(int n, int minutesDie, int minutesAll) {
    
    int t = minutesAll/minutesDie;
    int res=0;
    res=log(n)/log(1+t);
    return round(res+0.5);   //对小数点后一位 四舍五入
}

int main() {

    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _minutesDie;
    cin >> _minutesDie;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _minutesAll;
    cin >> _minutesAll;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = findPoisonWine(_n, _minutesDie, _minutesAll);
    cout << res << endl;
    
    return 0;

}
