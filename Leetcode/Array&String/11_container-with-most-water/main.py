from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l, r = 0, len(height) - 1
        while l < r:
            area = min(height[l], height[r]) * (r - l)
            ans = max(area, ans)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans


if __name__ == '__main__':
    heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    res = Solution().maxArea(heights)
    print(res)
