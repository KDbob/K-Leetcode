from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reach = 0
        for i in range(n):
            if i > reach:
                return False
            reach = max(i + nums[i], reach)
        return True

    def canJump2(self, nums: List[int]) -> bool:
        n = len(nums)
        last = n - 1
        for i in range(n - 2, -1, -1):
            if i + nums[i] >= last:
                last = i
        return last == 0


if __name__ == '__main__':
    nums = [2, 3, 1, 1, 4]
    res = Solution().canJump2(nums)
    if res:
        print("可到达")
    else:
        print("不可到达")
