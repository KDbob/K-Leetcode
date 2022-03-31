#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

给定一个按照升序排列的整数数组 `nums`，和一个目标值 `target`。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 `target`，返回 `[-1, -1]`。

**进阶：**

- 你可以设计并实现时间复杂度为 `O(log n)` 的算法解决此问题吗？

 

**示例 1：**

```
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

**示例 2：**

```
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
```

**示例 3：**

```
输入：nums = [], target = 0
输出：[-1,-1]
```

 

# 解题思路

## 方法一：二分查找

- 利用二分查找可以利用由于有序的特性，将查找时间缩短至log2N
- 二分查找分别考虑target是first和last的情况
  - ★即target==mid的时候需要继续划分，划分略有不同
    - 如果找first情况，下轮继续寻找[left ,mid]
    - 如果找last情况，下轮继续寻找[left, mid-1]
  - 另一种思路：寻找**第一个大于等于target的数**即first，寻找**第一个大于target的数**即last



### 算法实现

```c++
int findFirstIndx(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
            // 下轮继续寻找[mid+1, high]
            low = mid + 1;
        } else if (nums[mid] == target) {
            // 下轮继续寻找[left ,mid]
            high = mid;
        } else {
            // 下轮继续寻找[left, mid-1]
            high = mid - 1;
        }
    }
    if (nums[low] == target) return low;
    return -1;
}

int findLastIndx(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (nums[mid] < target) {
            // 下轮继续寻找[mid+1, high]
            low = mid + 1;
        } else if (nums[mid] == target) {
            // 下轮继续寻找[mid, right]
            low = mid;
        } else {
            // 下轮继续寻找[left, mid-1]
            high = mid - 1;
        }
    }
    return low;
}

/**
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * @param nums 按照升序排列的整数数组
 * @param target 目标值
 * @return 目标值在数组中的开始位置和结束位置
 */
vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return vector<int>{-1, -1};
    }

    int first = findFirstIndx(nums, target);
    if (first == -1) {
        return vector<int>{-1, -1};
    }
    int last = findLastIndx(nums, target);
    return vector<int>{first, last};
}
```



# 知识点总结

- 因为整除2会导致low的下标一直无法+1，需要合并low的

```
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
```



