/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次

*/


class MinStack {
public:
    /** initialize your data structure here. */
    // 辅助栈
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if(m.empty()||x<=m.top())
            m.push(x);
    }
    
    void pop() {
        if(s.top()==m.top())
            m.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return m.top();

    }
private:
    stack<int> s;
    stack<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */