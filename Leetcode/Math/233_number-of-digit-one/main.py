class Solution:

    def countDigitOne(self, n: int) -> int:
        """
        给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
        《枚举法》
        :param n: 一个整数
        :return: 所有小于等于 n 的非负整数中数字 1 出现的个数
        """
        k, mulk, = 0, 1  # k是没有作用的，只是从C++代码迁移过来表示从0开始的位
        sum = 0
        while n >= mulk:
            k += 1
            n_1 = n % (mulk * 10)
            sum += n // (mulk * 10) * mulk + min(max(n_1 - mulk + 1, 0), mulk)
            mulk *= 10
        return sum


if __name__ == '__main__':
    solution = Solution()
    print(solution.countDigitOne(100))  # expect:21
