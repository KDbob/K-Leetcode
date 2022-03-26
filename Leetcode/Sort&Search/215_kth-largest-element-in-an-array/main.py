# 215. 数组中的第K个最大元素
import random
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        def quick_seletor(l: int, r: int, index: int) -> int:
            q = self.random_partition(nums, l, r)
            if q == index:
                return nums[q]
            else:
                return quick_seletor(q + 1, r, index) if q < index else quick_seletor(l, q - 1, index)

        n = len(nums)
        return quick_seletor(0, n - 1, n - k)

    @staticmethod
    def random_partition(nums: list, p: int, r: int) -> int:
        k = random.randint(p, r)
        nums[k], nums[r] = nums[r], nums[k]
        x = nums[r]
        i = p - 1
        for j in range(p, r):
            if nums[j] < x:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        i += 1
        nums[i], nums[r] = nums[r], nums[i]
        return i


if __name__ == '__main__':
    nums = [3, 2, 1, 5, 6, 4]
    res = Solution().findKthLargest(nums, 2)
    print(res)  # expect: 5
