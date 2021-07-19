# 227. 基本计算器Ⅱ

给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

# 解题思路

1. 将数据根据规律压入栈中（遍历字符串）

   1. 如果是数字类型，循环取数

      > 考虑数字类型是不是被遍历完了，比如“42”

   2. 如果是"+-*/"查看presign的类型

      > 注：遍历到最后一个字符时，也需要执行步骤2做计算

      1.乘法和除法，直接求值（用到了presign）

      > 和栈顶元算相运算

      2.加法和减法，直接压入栈中

      > 注意正负号

      3.如果是运算符类型，更新presign

2. 将所有压入栈中的数据相加

### 准备数据结构

```c++
presign // 记录这个操作数之前的符号
stack	// 栈，用vector作栈
```



# 初步代码实现

```c++
int calculate(string s) {
    vector<int> stack;
    char presign = '+';
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            int num = int(c - '0');
            if (presign == '+' || presign == '-') {
                if (presign == '+') {
                    stack.push_back(+num);
                } else if (presign == '-') {
                    stack.push_back(-num);
                }
            } else {
                int top = stack.back();     // 记得将栈顶的元素弹出
                stack.pop_back();
                if (presign == '*') {
                    stack.push_back(top * num);
                } else if (presign == '/') {
                    stack.push_back(top / num);
                }
            }
        } else {
            switch (c) {
                case '+':
                    presign = '+';
                    break;
                case '-':
                    presign = '-';
                    break;
                case '*':
                    presign = '*';
                    break;
                case '/':
                    presign = '/';
                    break;
            }
        }
    }
    return accumulate(stack.begin(), stack.end(), 0);
}
```

## 存在的问题

1. 42这种数字要处理★
2. 字符转换成数字类型
3. 压入的数字需要带正负

# 最终代码实现（参考官方代码）

``````c++
int calculate(string s) {
    vector<int> stack;
    char presign = '+';
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + int(c - '0');
        }
        if (!isdigit(c) && c != ' '|| i == s.length()-1) {
            switch (presign) {
                case '+':
                    stack.push_back(+num);
                    break;
                case '-':
                    stack.push_back(-num);
                    break;
                case '*':
                    stack.back() *= num;
                    break;
                case '/':
                    stack.back() /= num;
                    break;
            }
            presign = c;
            num = 0;
        }
    }
    return accumulate(stack.begin(), stack.end(), 0);
}
``````

## 关键代码解读

```c++
if (!isdigit(c) && c != ' '|| i == s.length()-1)
等价于：是+-*/符号 or 是最后一个字符串
```



# 知识点总结

1. vector代码的写法可以简练

   ```c++
   stack.pop_back();
   stack.push_back(top * num);
   // 等价于：
   stack.back() *= num
   ```

2. vector内所有元素相加

   ```c++
    accumulate(stack.begin(), stack.end(), 0)
   ```

3. 遍历到最后一个字符串需要继续做计算操作

   ```c++
   if (!isdigit(c) && c != ' '|| i == s.length()-1)
   ```

   