// 326. 3的幂
// Created by kaide on 2021/6/2.
//
#include <string>
#include <math.h>

using namespace std;

/** 验证一个数是否是3的幂次
 * 《方法一二：循环整除/三进制》
 * @param n 数字
 * @return y o n
 */
bool isPowerOfThree1(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
        n = n / 3;
    }
    return n == 1;
}

/** 《方法三：对数公式》
 * @param n
 * @return
 */
bool isPowerOfThree3(int n) {
    if (n < 1) return false;
    double a = log10(n) / log10(3);
    return a == floor(a);
}

/** 《方法四：利用整数限制》
 * @param n 数字
 * @return y o n
 */
bool isPowerOfTree3(int n) {
    if (1162261467 % n == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    if (isPowerOfThree1(27)) {
        printf("is power of three\n");  // expect
    } else {
        printf("not power of three\n");
    }

    if (isPowerOfThree3(36)) {
        printf("is power of three\n");
    } else {
        printf("not power of three\n"); // expect
    }
}