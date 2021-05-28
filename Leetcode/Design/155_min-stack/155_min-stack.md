#### [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)

设计一个支持 `push` ，`pop` ，`top` 操作，并能在常数时间内检索到最小元素的栈。

- `push(x)` —— 将元素 x 推入栈中。
- `pop()` —— 删除栈顶的元素。
- `top()` —— 获取栈顶元素。
- `getMin()` —— 检索栈中的最小元素。

 

**示例:**

```
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

# 解题思路

> 本题的主要目的是问能在常数时间内检索到最小元素，而不是关于栈的设计。

## 方法一：借助辅助栈

##### 根据栈的先进后出性质有

- 如果其他元素（假设b、c、d）在元素（假设a）之前入栈，那么无论这个栈在之后经历了什么操作：
  - 只要a元素在栈中，那么b、c、d元素就一定在栈中

根据这个性质，可以根据<u>栈顶元素的来标记对应栈顶时，该栈的最小值</u>。

该思想也是空间换时间的思想，具体做法：

#### 准备数据结构

`stack<int> minStk; `：辅助栈，用于标记次栈顶所对应的之前的最小值。

`stack<int> stk;`：用于执行栈的基本操作。

> 初始时：min_stack的栈底值为INT_MAX

#### 算法流程

- 栈（MinStack）入栈时操作时，将入栈元素与min_stack的栈顶元素比较：
  - 如果入栈元素小于min_stack的栈顶元素，将该元素压入min_stack中
  - 如果入栈元素大于min_stack的栈顶元素，将min_stack的栈顶元素值压入min_stack中
- 栈（MinStack）做出栈操作时，同时将min_stack的栈顶元素做出栈操作

#### 代码实现

```C++
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
```



