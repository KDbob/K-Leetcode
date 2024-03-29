#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

> 滚动数组

给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 

**示例 1：**

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**示例 2：**

```
输入：nums = [1]
输出：1
```

**示例 3：**

```
输入：nums = [0]
输出：0
```

**示例 4：**

```
输入：nums = [-1]
输出：-1
```

**示例 5：**

```
输入：nums = [-100000]
输出：-100000
```

# 解题思路

## 方法一：动态规划

假设$f(i)$表示**以第i个数结尾**的“连续子数组的最大和”，那么由本题所求是$max\{f(i)\}$(其中0<i<n-1)。

- 因此可以求出所有的$f(i)$，取其中最大的一个，即为所求

考虑$f(i)$的转移方程：

> 如何求f(i)，**考虑nums[i]单独成为一段，还是加入f(i-1)对应的那一段**。取决于这两者更大的那个

$$
f(i) = max\{f(i-1)+nums[i],nums[i]\}
$$



初始值：$f(0)=nums[0]$

##### 优化

容易想到使用一个一维数组存放f(0)~f(n-1)的值，空间复杂度为$O(n)$

由于每次迭代只需使用前一个f(i-1)，借助“滚动数组”的思想，只需要设置两个变量即可.

`int f_max = nums[0]`：最大的f(i)值

`int f_pre = nums[0]`：维护对于当前 f(i)的 f(i−1)的值是多少

#### 代码实现

```C++
int maxSubArray(vector<int> &nums) {
    int f_pre = nums[0];
    int f_max = f_pre;
    for (int i = 1; i < nums.size(); i++) {
        f_pre = max(nums[i], f_pre + nums[i]);
        f_max = max(f_max, f_pre);
    }
    return f_max;
}
```

