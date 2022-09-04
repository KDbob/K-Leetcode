

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True

        max_len = 1
        start = 0
        for l in range(2, n+1):
            for i in range(0, n):
                # j - i + 1 = L
                j = l + i - 1
                if j >=n:
                    break
                if s[i] != s[j]:
                    dp[i][j] = False
                else:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1]

                if dp[i][j] and l > max_len:
                    max_len = l
                    start = i

        return s[start:start + max_len]

if __name__ == '__main__':
    s = "babad"
    res = Solution().longestPalindrome(s)
    print(res)