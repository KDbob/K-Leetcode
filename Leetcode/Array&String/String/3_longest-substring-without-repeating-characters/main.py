class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        occ = set()
        rk, ans = -1, 0
        for k in range(n):
            if k != 0:
                occ.remove(s[k - 1])  # 移除滑动窗口上个起始的元素
            while rk + 1 < n and s[rk + 1] not in occ:
                occ.add(s[rk + 1])
                rk += 1
            ans = max(rk - k + 1, ans)
        return ans


if __name__ == '__main__':
    s = "abcabcbb"
    res = Solution().lengthOfLongestSubstring(s)
    print(res)
