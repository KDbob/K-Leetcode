from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        def binarySearch(lower: bool):
            left, right = 0, len(nums) - 1
            ans = len(nums)     # len为1时，满足right_indx = 0
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] > target or (lower and nums[mid] >= target):
                    right = mid - 1
                    ans = mid
                else:
                    left = mid + 1
            return ans

        left_indx = binarySearch(True)
        right_indx = binarySearch(False) - 1
        if left_indx <= right_indx < len(nums) and nums[left_indx] == target and nums[right_indx] == target:
            return [left_indx, right_indx]
        return [-1, -1]


if __name__ == '__main__':
    nums = [5, 7, 7, 8, 8, 10]
    res = Solution().searchRange(nums, 8)
    print(res)  # expect: [3, 4]

    res2 = Solution().searchRange(nums, 6)
    print(res2)  # expect: [-1,-1]

    nums2 = [1]
    res3 = Solution().searchRange(nums2, 1)
    print(res3)