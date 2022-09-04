

class Solution:
    def calculate(self, s: str) -> int:
        stk = []
        n = len(s)
        num = 0
        pre_sign = '+'
        for i in range(n):
            if s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if s[i] in '+-*/' or i == n-1:
                if pre_sign == '+':
                    stk.append(num)
                elif pre_sign == '-':
                    stk.append(-num)
                elif pre_sign == '*':
                    stk.append(stk.pop() * num)
                else:
                    stk.append(int(stk.pop() / num))  # stk.pop() // num 对 -3//2 = -2
                pre_sign = s[i]
                num = 0
        return sum(stk)

if __name__ == '__main__':
    s = "14-3/2"
    res = Solution().calculate(s)
    print(res)
