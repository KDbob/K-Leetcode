from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = list()
        n = len(nums)
        for first in range(n):
            if first > 0 and nums[first] == nums[first - 1]:
                continue
            third = n - 1
            target = -nums[first]
            for second in range(first + 1, n):
                if second > first + 1 and nums[second] == nums[second - 1]:
                    continue
                while second < third and nums[second] + nums[third] > target:
                    third -= 1
                if second == third:
                    break
                if nums[first] + nums[second] + nums[third] == 0:
                    ans.append([nums[first], nums[second], nums[third]])
        return ans


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]
    res = Solution().threeSum(nums)
    print(res)  # expect：[[-1,-1,2],[-1,0,1]]
