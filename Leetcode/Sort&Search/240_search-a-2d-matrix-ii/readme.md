#### [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

> #二分搜索 #规律

编写一个高效的算法来搜索 `m x n` 矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid2.jpg)

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid.jpg)

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
```

# 解题：Z字形查找

## 算法思想

从右上角(0, n - 1)进行搜索，在每一步搜索中希望以(x, y)为右上角，matrix的左下角为左下角

> 行的范围为[x, m-1]
>
> 列的范围为[0, y]

- 如果matrix[x, y] = target，说明搜索完成
- 如果matrix[x, y] > target，**所有位于y列的数据都是严格大于target的**，将y-1（左移）
- 如果matrix[x, y] < target，**所有位于x行的数据都是严格小于target的**，将x+1（下移）

## 复杂度分析

- 时间复杂度O(m+n)
  - 最差情况左下角，至多下移m次，左移n次

- 空间复杂度O(1)