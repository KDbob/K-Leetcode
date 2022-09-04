from typing import List
from collections import Counter


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        cnt = Counter(tuple(row) for row in grid)
        return sum(cnt[col] for col in zip(*grid))


if __name__ == '__main__':
    grid = [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]]
    res = Solution().equalPairs(grid)
    print(res)  # expect: 3
