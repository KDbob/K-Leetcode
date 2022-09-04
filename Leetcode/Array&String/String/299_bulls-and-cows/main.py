class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        b, c = 0, 0
        s_cnt, g_cnt = [0] * 10, [0] * 10
        for i, j in zip(secret, guess):
            if i == j:
                b = b + 1
            else:
                s_cnt[int(i)] += 1
                g_cnt[int(j)] += 1
        c = sum(min(s, g) for s, g in zip(s_cnt, g_cnt))
        return f'{b}A{c}B'


if __name__ == '__main__':
    secret = "1807"
    guess = "7810"
    res = Solution().getHint(secret, guess)
    print(res)
