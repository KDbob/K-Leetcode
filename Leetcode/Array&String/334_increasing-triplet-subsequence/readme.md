#### [334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)

> #数组 #贪心

给你一个整数数组 `nums` ，判断这个数组中是否存在长度为 `3` 的递增子序列。

如果存在这样的三元组下标 `(i, j, k)` 且满足 `i < j < k` ，使得 `nums[i] < nums[j] < nums[k]` ，返回 `true` ；否则，返回 `false` 。

> 注★：i,j,k不一定要连续

**示例 1：**

```
输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
```

**示例 2：**

```
输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
```

**示例 3：**

```
输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
```

## 方法一：借助辅助数组

对于每个位置，维护两个数组：

leftMin[i]：对于每个位置，记录该位置之前的最小数

rightMax[i]：对于每位置，记录该位置后面的最大数

#### 数据结构

`vector<int> leftMin(n);`

`vector<int> rightMax(n);`

#### 算法流程

1. 遍历一次数组，对于每个位置，记录该位置之前的最小数

   > leftMin[0]起到哨兵的作用★

   - 更新当前位置之前的最小数

2. 遍历一次数组（逆序），对于每个位置，记录该位置之后的最大数

   > leftMax[n-1]起到哨兵的作用★

   - 更新当前位置之后的最大数

3. 从1～n-1遍历比较
   - 如果存在leftMin[k] < nums[k] < RightMax[k]，返回ture
   - 遍历结束，未找到。返回false

#### 代码实现

```C++
bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMin(n);
    leftMin[0] = nums[0];
    for (int i = 1; i < n ; ++i) {
        leftMin[i] = min(leftMin[i - 1], nums[i]);
    }
    vector<int> rightMax(n);
    rightMax[n - 1] = nums[n - 1];
    for (int j = n-2; j >= 0 ; --j) {
        rightMax[j] = max(rightMax[j + 1], nums[j]);
    }
    for (int k = 1; k < n -1 ; ++k) {
        if (leftMin[k] < nums[k] && nums[k] < rightMax[k]) {
            return true;
        }
    }
    return false;
}
```

#### 复杂度分析

- 时间复杂度：O(n)

  > 三次遍历

- 空间复杂度：O(n)

  - 借助两个辅助数组

  

## 方法二：贪心算法（TODO）

> 相比于方法一，能将空间复杂度优化到O(1)

上述做法的贪心思想是：为了找到递增的三元子序列，first和second 应该尽可能地小，此时找到递增的三元子序列的可能性更大。

#### 数据结构

两个变量：first、second

#### 贪心算法的做法

1. 如果 num > second，则找到了一个递增的三元子序列，返回 true
2. 否则，如果 num > first，则将second的值更新为num；
3. 否则，将 firs t的值更新为num

#### 需要证明贪心算法★



# 总结

1. python中创建定长数组的方法：[0] * n