from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        cur = []
        def backtrace(idx):
            if len(cur) == k:
                res.append(cur[:])
            else:
                for i in range(idx, n + 1):
                    if i not in cur:
                        cur.append(i)
                        backtrace(i + 1)
                        cur.pop()
        backtrace(1)
        return res


if __name__ == '__main__':
    res = Solution().combine(4, 2)
    print(res)
