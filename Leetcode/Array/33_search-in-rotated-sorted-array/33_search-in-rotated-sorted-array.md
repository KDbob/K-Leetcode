#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

整数数组 `nums` 按升序排列，数组中的值 **互不相同** 。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,5,6,7]` 在下标 `3` 处经旋转后可能变为 `[4,5,6,7,0,1,2]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，如果 `nums` 中存在这个目标值 `target` ，则返回它的下标，否则返回 `-1` 。

 

**示例 1：**

```
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

**示例 2：**

```
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
```

**示例 3：**

```
输入：nums = [1], target = 0
输出：-1
```

 

## 解题思路

## 方法一：二分查找

### 观察规律

- 若按标准的二分查找，需要整个数组都是有序的。

- 旋转数组的特点：将旋转数组一分为二的话：必存在有一部分是有序的数组

因此可以设计以下的二分查找方法：

### 在常规的二分查找时候，在mid分割的两部分[l, mid]和[mid + 1, r]，判断哪部分是有序的：

- 否则恰好查找值为nums[mid]

- 如果[l, mid -1]是有序数组，且target的大小满足[nums[l], nums[mid])，应该将搜索范围缩小至[l, mid -1]，否则在[mid + 1, r]中查找。

- 如果[mid, r]是有序数组，且target的大小满足(nums[mid +1], nums[r]], 应该将搜索范围缩小至[mid + 1, r], 否则在[l, mid -1]中寻找。

  > 以上两个“如果”是互斥关系，即执行了第一个就不会执行下一个

#### 代码实现

```c++
int search(vector<int> &nums, int target) {
    int n = nums.size();
    if (!n) return -1;
    if (n == 1) return nums[0] == target ? 0 : -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if (nums[mid] <= nums[l]) {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}
```

# 知识点总结

- 缩小的范围不包括mid，因此区间都是[l, mid -1]和[mid + 1, r]

- 判断是否有序数组在本题中可以将nums的边界值做比较

  > ```c++
  > // 二分查找一次只缩小一半
  > if (nums[l] <= nums[mid]) {	// 加等号是因为可能只剩1个数
  >     if (nums[l] <= target && target < nums[mid]) {
  >         r = mid - 1;
  >     } else {
  >         l = mid + 1;
  >     }
  > } else if (nums[mid] <= nums[l]) { // 这个判断条件其实也可以直接省略成else
  >     if (nums[mid] < target && target <= nums[r]) {
  >         l = mid + 1;
  >     } else {
  >         r = mid - 1;
  >     }
  > }
  > ```

