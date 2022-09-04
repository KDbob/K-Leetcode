#### [2352. 相等行列对](https://leetcode.cn/problems/equal-row-and-column-pairs/)

难度中等2收藏分享切换为英文接收动态反馈

给你一个下标从 **0** 开始、大小为 `n x n` 的整数矩阵 `grid` ，返回满足 `Ri` 行和 `Cj` 列相等的行列对 `(Ri, Cj)` 的数目*。*

如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg)

```
输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
输出：1
解释：存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg)

```
输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
输出：3
解释：存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]
```

 

# 方法一：hash表

## 解题思路

1. 先统计行的次数
2. 统计列的次数，如果相同ans+=1



# 总结

1. python中简洁的写法：

```python
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        cnt = Counter(tuple(row) for row in grid)
        return sum(cnt[col] for col in zip(*grid))
```

- collection模块的函数：Counter()

  > 对每个元组统计次数

- zip(*grid)
  - zip()：拉链函数，成组
  - *grid拆包再zip，相当于取每列成元组
- sum()函数：求和