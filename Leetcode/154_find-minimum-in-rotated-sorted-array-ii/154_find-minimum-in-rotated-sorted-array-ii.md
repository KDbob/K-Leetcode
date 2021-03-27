#### [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

假设按照**升序**排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。请找出其中最小的元素。

示例 1：

```
输入：nums = [3,4,5,1,2]
输出：1

```

示例 2：

```
输入：nums = [4,5,6,7,0,1,2]
输出：0
```


示例 3：

```
输入：nums = [1]
输出：1
```

# 解题思路

题目说明了数组是升序数组经过某个点进行的旋转。

### 发现规律

1. 区分是否旋转数组

```c++
[2,3,4,5,6,7]  // 未旋转，7>2,即A[n-1] > A [0]

[4,5,6,7,2,3]  // 已旋转，4<3,即A[n-1] < A [0]
```

2. 旋转数组中最小数所在位置的特点

> 设最小数所在的位置是i

-  [4,5,6,7,2,3] 中的7>2，即A[i-1] > A[i]，其中最小数是2

### 算法实现

借助二分查找（Binary Search）的思想来查找

#### 准备数据结构

二分查找需要用到三个游标：

```c++
int left, right, mid;
```

#### 算法流程

1. 选取中间的值A[mid]

2. A[0] > mid，则继续在左侧查找（修改游标位置）

3. A[0] < mid，则继续在右侧查找（修改游标位置）

4. 结束条件：

   > 参考 [4, 5, 6, 7, 2, 3]，中的7 > 2，程序当前查找的值是A[mid]

   1. A[mid-1] > A[mid] ，说明A[mid]是最小值
   2. A[mid] > A [mid + 1]，说明A[mid]是最小值

5. 未找到最小值，返回-1

```c++
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    if (nums[0] <= nums[right]) return nums[0];     // 如果是非旋转序列
    while (left < right) {
        int mid = (right + left) /2;
        if (mid >= 1 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[0] < nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
```

# 知识点总结

#### 1.Leetcode问题Line 1034: Char 34: runtime error: addition of unsigned offset to

原因是：vector[-1]这种的话，数组越界

解决：前面多加一个条件：mid>=1，防止出现vector[-1]

```c++
if (mid >= 1 && nums[mid] < nums[mid - 1])
```

