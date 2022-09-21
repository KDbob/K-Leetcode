class Solution:

    def minWindow(self, s: str, t: str) -> str:
        ori = {}.fromkeys(set(t), 0)
        for ch in t:
            ori[ch] += 1

        cnt = {}.fromkeys(set(t), 0)

        def check():
            for k, v in ori.items():
                if cnt[k] < v:
                    return False
            return True

        l, r = 0, -1
        min_len = 99999
        ansL, ansR = -1, -1
        while r < len(s):
            r += 1
            if r < len(s) and s[r] in ori:
                cnt[s[r]] += 1

            while check() and l <= r:
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    ansL = l
                if s[l] in ori:
                    cnt[s[l]] -= 1
                l += 1
        return "" if ansL==-1 else s[ansL: ansL+min_len]


if __name__ == '__main__':
    s = "a"
    t = "aa"
    res = Solution().minWindow(s, t)
    print(res)
