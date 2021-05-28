
//01_判断素数
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, i;
    bool isPrime = true;
 
    cout << "输入一个正整数: ";
    cin >> n;
 
    for(i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << "是素数";
    else
        cout << "不是素数";

    return 0;
}

/***************************************************************/

//02_GCD 最大公约数
#include<bits/stdc++.h>
using namespace std;
// x*y=最小公倍数*最大公约数
//辗转相除法
int gcd_1(int a,int b){
    if(a<b)     swap(a,b);
    if(a%b==0)  return b;
    else        return gcd_1(b,a%b);
}

//辗转相减法
int gcd_2(int a,int b){
    if(a<b)     swap(a,b);
    if(a%b==0)  return b;
    else        return gcd_2(b,a-b);
}

int main(){
    int a=12,b=8;
    int res=gcd_2(a,b);
    cout<<res<<endl;
}

/***************************************************************/

//03_Bases 基数问题

#include <bits/stdc++.h>
using namespace std;
 

void bases(int x){
    cout << "8进制:" << oct << x << endl;  
    cout << "10进制" << dec << x << endl;  
    cout << "16进制:" << hex << x << endl;  
    cout << "2进制: " << bitset<32>(x) << endl;  //<32>：表示保留32位输出
}

vector<int> dec2bit(int x,int n){
    vector<int> res;
    while(x){
        res.push_back(x%n);
        x=x/n;
    }
    return res;
}

int main()  
{  
    bases(43);
    vector<int> res=dec2bit(43,8);
    cout<<res.size()<<endl;

    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    return 0;  
}
