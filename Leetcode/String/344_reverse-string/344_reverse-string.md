#### [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 

示例 1：

```
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```


示例 2：

```
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```

# 解题思路

#### 准备数据结构

准备两个指针

- i指向数组的首部
- j指向数组的尾部

#### 算法流程

0. 初试化时，i指向数组的首部，j指向数组的尾部

1. 交换A[i++]和A[j--]的值，遍历数组

   > 结束条件是i==

#### 复杂度分析

时间复杂度：$O(n)$

空间复杂度：$O(1)$

# 知识点总结

```shell
Line 1034: Char 34: runtime error: addition of unsigned offset to 0x6020000001b0 overflowed to 0x6020000001af (stl_vector.h)
```

```c++
void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i != j) {
            swap(s[i++], s[j--]);
        }
}
```

原因：s[i++]可能超出数组的长度。

解决：修改条件

```c++
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
}
```

