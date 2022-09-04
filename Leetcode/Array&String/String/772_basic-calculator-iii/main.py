

class Solution:
    def calculate(self, s: str) -> int:
        pass

if __name__ == '__main__':
    s = "2*(5+5*2)/3+(6/2+8)"
    res = Solution().calculate(s)
    print(res)  # expect: 21
