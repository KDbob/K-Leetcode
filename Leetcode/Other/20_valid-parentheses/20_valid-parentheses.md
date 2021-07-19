#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

 

**示例 1：**

```
输入：s = "()"
输出：true
```

**示例 2：**

```
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```
输入：s = "(]"
输出：false
```

**示例 4：**

```
输入：s = "([)]"
输出：false
```

**示例 5：**

```
输入：s = "{[]}"
输出：true
```

# 解题思路

## 方法一：栈

>  因为每个括号都是成对的，并且最内侧的右括号一定先出现。可以于是根据成对消除的思想

### 准备数据结构

stack<char> stk;

### 算法流程

1. 遍历字符串
   - 一旦遇到左括号，将左括号压入栈中
   - 一旦遇到右括号，对比栈顶元素：
     - 如果与之匹配，将栈顶括号出栈
     - 如果与栈顶元素不匹配，返回false
2. 遍历完成如果栈中无元素，返回true。否则返回false

### 代码实现

初步代码实现

```C++
bool isValid(string s) {
    stack<char> stk;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stk.push(s[i]);
        } else {
            char match;
            switch (s[i]) {
                case '}':
                    match = '{';
                    break;
                case ']':
                    match = '[';
                    break;
                case ')':
                    match = '(';
                    break;
                default:
                    match = ' ';
                    break;
            }
            if (stk.empty()) return false;
            if (match != stk.top()) {
                return false;
            } else {
                stk.pop();
            }
        }
    }
    if (stk.empty()) {
        return true;
    } else {
        return false;
    }
}
```

代码改进

- 因为括号是成对出现的，通过前部分判断字符串长度是否为奇数。
- 用switch显的代码臃肿，可以定义静态的括号匹配规则。
  - 可以优化switch部分代码
  - 可以针对key，对if条件简写

- stk.empty的代码可以简写

```c++
bool isValid(string s) {
    stack<char> stk;
    if (s.size() % 2 == 1) return false;
    for (int i=0; i < s.size(); i++) {
        if (!pairs.count(s[i])) {  // 等价于 if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            stk.push(s[i]);
        } else if (!stk.empty() && pairs[s[i]] == stk.top()){
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}
```

