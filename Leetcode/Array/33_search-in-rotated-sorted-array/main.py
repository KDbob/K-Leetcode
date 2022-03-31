from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
            if nums[low] <= nums[mid]:  # 这部分是有序的
                if nums[low] <= target < nums[mid]:     #不包含mid，因此闭区间
                    high = mid - 1
                else:
                    low = mid + 1
            elif nums[mid] <= nums[high]:  # 这部分是有序的
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1


if __name__ == '__main__':
    nums = [4, 5, 6, 7, 0, 1, 2]
    ret = Solution().search(nums, 0)
    print(ret)  # expect: 4
