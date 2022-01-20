// 233. 数字 1 的个数
// Created by bob on 2022/1/15.
//
#include "iostream"

using namespace std;

class Solution {
public:

    /**
     * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
     * 《枚举法》
     * @param n 一个整数
     * @return 所有小于等于 n 的非负整数中数字 1 出现的个数
     */
    int countDigitOne(int n) {
        long long mulk = 1;
        int sum = 0;
        for (int k = 0; n >= mulk; ++k) {
            int n_1 = n % (mulk * 10);
            sum += n / (mulk * 10) * mulk + min(max(n_1 - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return sum;
    }
};


int main() {
    Solution solution = Solution();
    int i = solution.countDigitOne(100);
    printf("%d", i);
}