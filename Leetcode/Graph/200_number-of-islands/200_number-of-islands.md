#### [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

#图的遍历 #DFS #BFS #并查集 #面试题

给你一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

**示例 1：**

```
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```

**示例 2：**

```
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
```

 

**提示：**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` 的值为 `'0'` 或 `'1'`

# 解题

## 方法一：DFS遍历

### 1. 思路

将grid看作是一个无向图

- `1`和`0`都看作是顶点
- 水平或者垂直的`1`看作相连

从任意一个顶点，进行图的遍历。完成整个图遍历的次数就是题目所求


### 2 编程

#### 2.1 数据结构

`int r, int c`:dfs递归函数的参数，用来标记图中的下标

#### 2.2 算法流程

1. 主函数遍历所有顶点：
   1. 如果这个顶点是'1'，进行DFS遍历图：
      - 遍历过的顶点置'0'

2. 遍历结束返回**遍历的次数**

#### 2.3 代码实现

```c++
class Solution {
private:
    void dfs(vector<vector<char>> &grid, int r, int c) {
        int rLen = grid.size();
        int cLen = grid[0].size();
        grid[r][c] = '0';   // 将遍历过的值修改为0
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < rLen && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < cLen && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int rLen = grid.size();
        int cLen = grid[0].size();
        int sum = 0; 
        for (int r = 0; r < rLen; ++r) {
            for (int c = 0; c < cLen; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    sum += 1;
                }
            }
        }
        return sum;
    }
};
```



### 3 复杂度分析

- 时间复杂度：$O(MN)$

  > 其中MN分别是行数和列数

- 空间复杂度：$O(MN)$

  - 最差情况是grid全'1'，此时的递归深度是MN


# 总结

- dfs的实现用递归较为方便，但是递归的深度和图的空间有关
  - dfs主要做的是将遍历过的值修改成0，这会影响主函数第二次选用顶点搜索
- python中的利用语法简化了判断语句🐱

```python
for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
    if 0 <= x < nr and 0 <= y < nc and grid[x][y] == '1':
        dfs(x, y)
```

