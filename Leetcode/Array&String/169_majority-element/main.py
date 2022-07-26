from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def count_in_range(target, low, high):
            return sum(1 for i in range(low, high + 1) if nums[i] == target)

        def majority_element_rec(low, high):
            if low == high:
                return nums[low]
            mid = (low + high) // 2
            left_majority = majority_element_rec(low, mid)
            right_majority = majority_element_rec(mid + 1, high)

            left_count = count_in_range(left_majority, low, high)
            right_count = count_in_range(right_majority, low, high)
            return left_majority if left_count > right_count else right_majority

        return majority_element_rec(0, len(nums) - 1)


if __name__ == '__main__':
    nums = [2, 2, 1, 1, 1, 2, 2]
    res = Solution().majorityElement(nums)
    print(res)
