from typing import List


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        tmp = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                tmp[j] += tmp[j - 1]    # 循环滚动的思想
        return tmp[-1]


if __name__ == '__main__':
    result = Solution().uniquePaths(3, 7)
    print(result)  # expect: 28
