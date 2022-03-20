from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        p0 = p1 = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == 1:
                nums[i], nums[p1] = nums[p1], nums[i]
                p1 += 1
            if nums[i] == 0:
                nums[i], nums[p0] = nums[p0], nums[i]
                if p0 < p1:
                    nums[i], nums[p1] = nums[p1], nums[i],
                p0 += 1
                p1 += 1


if __name__ == '__main__':
    nums = [2, 0, 2, 1, 1, 0]
    Solution().sortColors(nums)
    print(nums)  # expect：[0,0,1,1,2,2]
