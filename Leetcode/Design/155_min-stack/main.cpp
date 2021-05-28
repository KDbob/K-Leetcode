// 155. 最小栈
// Created by kaide on 2021/5/28.
//
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minStk.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        if (val < minStk.top()) {
            minStk.push(val);
        } else {
            minStk.push(minStk.top());
        }
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    stack<int> minStk;
    stack<int> stk;
};

int main() {
    MinStack stk = MinStack();
    stk.push(2);
    stk.push(0);
    stk.push(-3);
    printf("%d\n", stk.getMin());   // expect:-3
    stk.pop();
    printf("%d\n", stk.top());   // expect: 0
    printf("%d\n", stk.getMin());   // expect: 0
}