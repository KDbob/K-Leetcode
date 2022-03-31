from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = list()
        cur = []

        def traceback(open: int, close: int):
            if len(cur) == n * 2:
                ans.append("".join(cur))
            if open < n:
                cur.append("(")
                traceback(open + 1, close)
                cur.pop()
            if close < open:
                cur.append(")")
                traceback(open, close + 1)
                cur.pop()

        traceback(0, 0)
        return ans


if __name__ == '__main__':
    res = Solution().generateParenthesis(3)
    print(res)
