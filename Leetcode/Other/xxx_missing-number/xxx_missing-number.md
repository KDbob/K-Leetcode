### 缺失数字

给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

 

进阶：

你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?


示例 1：

输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 2：

输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 3：

输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
示例 4：

输入：nums = [0]
输出：1
解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。


提示：

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums 中的所有数字都 独一无二

# 解题思路

## 方法一：利用异或运算的性质

#### 因为异或运算 $\oplus$的特点

- 任何数和 0 做异或运算，结果仍然是原来的数，即$a \oplus 0=a$。
- 任何数和其自身做异或运算，结果是 0，即$a \oplus a=0$ 。
- 异或运算满足交换律和结合律，即 $a \oplus b \oplus a=b \oplus a \oplus a=b \oplus (a \oplus a)=b \oplus0=b$。

可以想象一个完整的数组（里面都是自然数），然后两个数组的值都相异或

- 由于未缺失的数是成对存在的，因此最后异或得到的值是缺失的

### 准备数据结构

`int res = n;`异或赋值

> 由于缺失的数组只会遍历n-1次，因此可以初始赋值为n。

### 算法流程

1. 遍历数组，将每个元素值与下标i异或：nums[i] ⊕ i
   - 异或并赋值给res
2. 返回res