# 题目描述：袋子中有N颗玻璃珠（N小于10000），我们通过下面的可选操作，将玻璃珠从袋子中取出，请问最少需要多少步可以将玻璃珠全部取出？
# 规则1. 移除1颗玻璃珠
# 规则2. 如果玻璃珠颗数可以被2整除，移除一半玻璃珠
# 规则3. 如果玻璃珠颗数可以被3整除，移除三分之二的玻璃珠
class Solution:
    def stepNum(self, N):
        if N <= 0:
            return -1

        def func(n):
            if n == 1:
                return 1
            else:
                if n % 2 == 0 and func(n // 2) < func(n - 1):
                    return 1 + func(n // 2)
                if n % 3 == 0 and func(n // 3) < func(n - 1):
                    return 1 + func(n // 3)
                else:
                    return 1 + func(n - 1)

        return func(N)

    def stepNum2(self, N):
        if N <= 0:
            return -1
        dp = [0, 1, 2, 3]

        for i in range(4, N):
            if i % 2 == 0 and dp[i // 2] < dp[i - 1]:
                dp.append(1 + dp[i // 2])
            if i % 3 == 0 and dp[i // 3] < dp[i - 1]:
                dp.append(1 + dp[i // 3])
            else:
                dp.append(1 + dp[i - 1])
        return dp[N]


if __name__ == '__main__':
    n = 10000
    # res = Solution().stepNum(n) # 第一种方法不建议，太多递归层了
    # print(res)
    res2 = Solution().stepNum2(n)
    print(res2)
