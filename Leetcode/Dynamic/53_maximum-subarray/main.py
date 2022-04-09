from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        f_max = f_pre = nums[0]
        for i in range(1, len(nums)):
            f_pre = max(nums[i], f_pre + nums[i])
            f_max = max(f_max, f_pre)
        return f_max


if __name__ == '__main__':
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    res = Solution().maxSubArray(nums)
    print(res)  # expect 6
