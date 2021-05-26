/*
题目描述：
给定一个乱序的栈，设计算法将其升序排列。
ps: 允许额外使用一个栈来辅助操作 

输入
[4, 2, 1, 3]
输出
[1, 2, 3, 4]

*/


stack<int> stackSort(stack<int> &stk) {
    stack<int> tmp;
    while (!stk.empty()) {
        int peak = stk.top();
        stk.pop();
        while (!tmp.empty() && tmp.top() > peak) {
            int t = tmp.top();
            tmp.pop();
            stk.push(t);
        }
        tmp.push(peak);
    }
    return tmp;
}

/*python

def stackSort(stk):
    tmp = []
    while stk:
        peak = stk.pop()
        while tmp and tmp[-1] > peak:
            t = tmp.pop()
            stk.append(t)
        tmp.append(peak)
    return tmp
*/