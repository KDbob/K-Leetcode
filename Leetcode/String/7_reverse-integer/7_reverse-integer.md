#### [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)

给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。


示例 1：

```
输入：x = 123
输出：321

```

示例 2：

```
输入：x = -123
输出：-321

```

示例 3：

```
输入：x = 120
输出：21

```

示例 4：

```
输入：x = 0
输出：0


```

# 解题思路

使用反转字符串的思想进行类比：将尾部的数字不断放到高位

在没有辅助栈/数组的帮助下进行pop数和push数字

```c++
//pop operation:
pop = x % 10;
x /= 10;
```

和

```C++
//pop operation:
pop = x % 10;
x /= 10;
```

那么实现的代码为：

```c++
int reverse(int x) {
    int rev = 0;
    while (x!=0) {
        int pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;
    }
    return rev;
}
```

## 特殊情况（考虑溢出）

>  int最大值是2147483647，最小值是-2147483648

- 如果8463847412反转，则得到2147483648，出现了溢出
- 如果7463847413反转，则得到3147483647，出现了溢出
  - 负数同理

3147483647X时，无论最后一位数是什么都，超过了2147483648

> 即：rev > INT_MAX/10：溢出

214748364X时，就要判断最后一次pop的数字8（即最高位）需要判断是否大于7。

> 即：rev==INT_MAX/10此时还不知道是否溢出，但是X如果>7则溢出。

### 代码实现

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// 此处的 INT_MAX/10 可以预防2147483646X这种位数已经超出了MAX位数的数
```

##### 但是7463847413根本就不可能出现，所以加一条判断就好了，那么最后的代码是：

```c++
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0; // 预判断：防止溢出
        rev = rev * 10 + pop;
    }
    return rev;
}
```

