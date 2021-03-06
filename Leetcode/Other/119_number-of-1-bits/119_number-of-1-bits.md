#### [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为[汉明重量](https://baike.baidu.com/item/汉明重量)）。

示例 1：

```c++
输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
```

# 解题思路

## 方法一：循环检查二进制位数

> 用到了位运算的知识，借助1的左移，即$2^i$
>
> 将n与$2^i$进行与运算，当且仅当n的i位为1时，运算结果不为0。

- 将1不断左移，比如1<<3 = $(1000)_2$
- 再将 $(1000)_2$与该二进制数n相&
  - 如果这次相&的结果为1，说明第3位（0位开始）的二进制数是1
  - 如果这次相&的结果为0，说明第3位（0位开始）的二进制数是0

### 代码实现

## 方法二：位运算优化

利用一个位运算公式

```tex
n&(n-1)
```

这个位运算公式，恰好把的二进制位中的最低位的 11 变为 00 之后的结果

6&(6-1)=4，其中：

6=$(110)_2$

4=$(100)_2$

运算结果 4 即为把 6 的二进制位中的最低位的 11 变为 00 之后的结果。

这样我们可以利用这个位运算的性质加速我们的检查过程，在实际代码中，我们不断让当前的 n与 n - 1做与运算，直到 n变为 0即可。因为每次运算会使得 n的最低位的 1 被翻转，因此运算次数就等于 nn 的二进制位中 11 的个数

### 代码实现

```c++
int hammingWeight(uint32_t n) {
    int res = 0;
    while (n) {
        n &= (n-1);
        res++;
    }
    return res;
}
```

# 知识点总结

- 一个实用的位运算公式：n&(n-1)

  > 它的作用是将最低位的1变成0

- C/C++中的uint32_t类型

  ```c++
  typedef unsigned int uint32_t;
  ```

  占4字节，32bit

  - Java中，没有无符号整数类型；在 Java 中，编译器使用[二进制补码](https://baike.baidu.com/item/二进制补码/5295284)记法来表示有符号整数。

