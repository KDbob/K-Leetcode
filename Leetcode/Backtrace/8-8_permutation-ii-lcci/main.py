from typing import List


class Solution:
    def permutation(self, S: str) -> List[str]:
        n = len(S)
        res = []
        chosen = []

        def backtrace(idx):
            seen = set()  # set作为局部变量的原因是，在这层(idx)不能选择重复的字母
            if idx == n:
                res.append("".join([S[i] for i in chosen]))
            else:
                for i in range(n):
                    if i not in chosen and S[i] not in seen:
                        chosen.append(i)
                        backtrace(idx + 1)
                        chosen.pop()
                        seen.add(S[i])

        backtrace(0)
        return res


if __name__ == '__main__':
    S = "qqe"
    res = Solution().permutation(S)
    print(res)
