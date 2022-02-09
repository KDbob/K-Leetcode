from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        nr = len(grid)
        if nr == 0:
            return 0
        nc = len(grid[0])
        def dfs(r, c):
            grid[r][c] = '0'
            for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
                if 0 <= x < nr and 0 <= y < nc and grid[x][y] == '1':
                    dfs(x, y)
        sum = 0
        for i in range(nr):
            for j in range(nc):
                if grid[i][j] == "1":
                    dfs(i, j)
                    sum += 1
        return sum


if __name__ == '__main__':
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]
    print(Solution().numIslands(grid))  # expect: 3
