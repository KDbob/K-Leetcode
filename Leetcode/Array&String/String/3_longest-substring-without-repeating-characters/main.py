class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        current = set()
        cnt = 0
        rk = -1
        for i in range(n):
            if i != 0:
                current.remove(s[i - 1])

            while rk + 1 < n and s[rk + 1] not in current:
                current.add(s[rk + 1])
                rk += 1

            cnt = max(cnt, rk + 1 - i)
        return cnt


if __name__ == '__main__':
    s = "abcabcbb"
    res = Solution().lengthOfLongestSubstring(s)  # expect: 3
    print(res)
