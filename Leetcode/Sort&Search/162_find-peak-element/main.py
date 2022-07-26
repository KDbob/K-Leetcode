import random
from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        idx = random.randint(0, n - 1)

        # 辅助函数
        def get(i: int) -> int:
            if i == -1 or i == n:
                return float('-inf')
            return nums[i]

        while not (get(idx - 1) < get(idx) > get(idx + 1)):
            if get(idx) < get(idx + 1):
                idx += 1
            else:
                idx -= 1
        return idx


if __name__ == '__main__':
    nums = [1, 2, 1, 3, 5, 6, 4]
    res = Solution().findPeakElement(nums)
    print(res)
