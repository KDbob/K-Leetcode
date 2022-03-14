#### [66. 加一](https://leetcode-cn.com/problems/plus-one/)

给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储**单个数字**。

你可以假设除了整数 0 之外，这个整数不会以零开头。

 

示例 1：

```
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
```


示例 2：

```
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
```


示例 3：

```
输入：digits = [0]
输出：[1]
```

### 注

**单个数字**：就是1～9。不存在[10, 12, 3]这种

# 解题思路

### 准备数据结构

进位标志：bool carry

> 表示是否要进位

游标：indx

> 初始指向最低位，如果有进位，index--

### 算法流程

> 将整个算法标记为①

1. 最低位是9，说明要进位 
   - 如果前面无数字，insert1
   - 前面有数字，重复执行 ①
2. 最低位是0～8，直接在最低位+1即可

### 复杂度分析

时间复杂度：$O(n)$

空间复杂度：$O(1)$

# 知识点总结

**循环体重构**：有重复的代码，使循环重构。使得代码简练

> 先判断再进入循环体，可以从(if...while) 改成：
>
> 先执行，再判断(do...while)

原始代码：

```c++
vector<int> plusOne_original(vector<int> &digits) {
    int indx = digits.size() - 1;
    bool carry ;
    if (digits[indx] == 9) {  // 最低位是9，说明要进位
        carry = true;
        digits[indx] = 0;
        indx --;
        while (carry) {
            carry = false;
            if (indx == -1) {
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[indx] == 9) {
                digits[indx] = 0;
                carry = true;
                indx --;
            } else {
                digits[indx] +=1;
            }
        }
    } else {
        digits[indx] += 1;
    }
    return digits;
}
```

重构代码：

```c++
vector<int> plusOne(vector<int> &digits) {
    int indx = digits.size() - 1;
    bool carry;
    do {
        carry = false;
        if (indx == -1) {
            digits.insert(digits.begin(), 1);
            break;
        }
        if (digits[indx] == 9) {
            digits[indx] = 0;
            carry = true;
            indx --;
        } else {
            digits[indx] +=1;
        }
    } while (carry);
    return digits;
}
```



