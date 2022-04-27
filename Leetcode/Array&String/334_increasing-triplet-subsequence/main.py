from typing import List


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        left_min = [0] * n
        left_min[0] = nums[0]
        for i in range(1, n):
            left_min[i] = min(left_min[i - 1], nums[i])
        right_max = [0] * n
        right_max[n - 1] = nums[n - 1]
        for j in range(n - 2, -1, -1):
            right_max[j] = max(right_max[j + 1], nums[j])
        for k in range(1, n - 1):
            if left_min[k] < nums[k] < right_max[k]:
                return True
        return False


if __name__ == '__main__':
    nums = [2, 1, 5, 0, 4, 6]
    res = Solution().increasingTriplet(nums)
    print(res)  # expect True
