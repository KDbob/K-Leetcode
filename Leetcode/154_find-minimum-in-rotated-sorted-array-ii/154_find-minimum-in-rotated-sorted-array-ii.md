#### [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

```
输入: [1,3,5]
输出: 1
```


示例 2：

```
输入: [2,2,2,0,1]
输出: 0
```

# 解题思路

#### 判断是否旋转数组

```c++
[1] [1,2,3] [1,1] // 非旋转数组
```

```c++
[3,1,3]	// 旋转数组
```

算法流程

1. 选取中间的值A[mid]

2. 比较A[mid]和A[right]

   > 一共有三种情况


- 第一种情况：A[mid] < A[right]，说明min在左侧（调整游标）

```c
[3,3,4,5,1,2,3,3]	// 如A[5]<A[7],即2<3，往左侧继续查找
```

- 第二种情况：A[mid] > A[right]，说明min在右侧（调整游标）

```c
[3,3,4,5,1,2,3,3] // 如A[2]>A[7],即4<7，往右侧继续查找
```

  - ★第三种情况：A[mid] == A[right]，只能说明A[right]有个一个替代值，可以缩小范围：right--

```c++
[3,3,3,1,1,3,3]		// 如A[mid] = A[right], 即3=3，将right游标左移一位
```

3. 结束条件：

> 参考 [4, 5, 6, 7, 2, 3]，中的7 > 2，程序当前查找的值是A[mid]

1. A[mid-1] > A[mid] ，说明A[mid]是最小值
2. A[mid] > A [mid + 1]，说明A[mid]是最小值

4. 未找到最小值，返回游标所在的值

根据153题的算法思想改进：

```c++
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    if (right == 0 || nums[0] < nums[right]) return nums[0];     // 如果是非旋转序列[1] [1,2,3] [1,1]
    int mid;
    while (left <= right) {
        mid = left + (right - left) /2;
        if (mid >= 1 && nums[mid] < nums[mid - 1]) {    // 防止出现mums[-1]
            return nums[mid];
        }
        if (mid <nums.size()-1 && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        if (nums[mid] < nums [right]) {
            right = mid - 1;
        } else if (nums[mid] > nums[right]){
            left = mid + 1;
        } else {
            right -=1;
        }
    }
    return nums[mid];
}
```



# 知识点总结

游标递减只能使用right--，而不能使用left++

> 因为c++中整除对减敏感：3/2=1，4/2=2

- 使用right--的计算

```c++
int left = 0,right = 4;
int mid = left + (right - left) / 2;	// mid =2
right --;
mid = left + (right - left) / 2; // mid =1
```

- 使用left++的计算

```c++
int left = 0,right = 4;
int mid = left + (right - left) / 2;	// mid =2
left --;
mid = left + (right - left) / 2; // mid =2
```

