#### [剑指 Offer 11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

```
输入：[3,4,5,1,2]
输出：1
```


示例 2：

```
输入：[2,2,2,0,1]
输出：0
```


注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

# 解题思路

旋转数组中数字可能重复

#### 发现规律

> 假设按二分查找的思想，设置三个游标：A[mid]是当前查找的元素，A[low]，A[high]控制搜索范围

假设数组中的最小数字是Xmin，**和数组中的最后一个数字A[high]**做比较有以下规律：

- Xmin左侧的元素一定>A[high]

  - 那么一旦查找的元素A[mid]>A[high]

    > →说明A[mid]一定是Xmin左侧的数字
    >
    > →可以缩小搜索范围，说明Xmin所在的位置在A[mid+1]~A[high]中

- Xmin右侧的元素一定<=A[high]

  - 查找到的元素A[mid]<A[high]

    > →说明A[mid]一定是Xmin右侧的数字，或者A[mid]就是Xmin
    >
    > →可以缩小搜索范围，说明Xmin所在的位置在A[low]~A[mid]中

  - 查找到的元素A[mid]=A[high]

    > ★A[mid]既可以是Xmin左侧的数字，也可能是Xmin右侧的数字。
    >
    > →唯一可以缩小范围的地方：high--（说明high有个替代品）

