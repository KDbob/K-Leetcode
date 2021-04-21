#### [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 

示例 1：

```
输入：haystack = "hello", needle = "ll"
输出：2
```


示例 2：

```
输入：haystack = "aaaaa", needle = "bba"
输出：-1
```


示例 3：

```
输入：haystack = "", needle = ""
输出：0
```

# 解题思路

## 一、简单匹配

#### 准备数据结构

int i，j = 0;

> 双指针：分别指向主串和子串的第一个位置。

bool flag = false;

> 用来标记是否进入了匹配模式，记k进入匹配模式的开始位置

### 算法流程

1. 设置i指向主串第一个位置，j指向子串的第一个位置

2. 比较两个指针所指向的字符，如果

   - 如果相等，即S[i]==T[j]时，i和j分别后移一位（从k这个位置进入了匹配模式）

     > 容易知道$k=i-j$

   - 如果不相等

     - 如果进入了匹配模式，则i退回到k的位置。即：$i-j+1，j=0$
     - 非匹配模式：$i++，j=0$

3. j遍历完成时，说明匹配成功；否则说明匹配失败。

#### 代码实现

```c++
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    int i = 0, j = 0;
    bool flag = false;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            flag = true;
        } else {
            if (flag) {
                i = i - j + 1;
                flag = false;
            } else {
                i++;
            }
            j = 0;
        }
    }
    if (j == needle.size()) {
        return i - j;
    } else {
        return -1;
    }
}
```

### 方法二：KMP算法（TODO）