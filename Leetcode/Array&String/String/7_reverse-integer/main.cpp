// 7. 整数反转
// Created by kaide on 2021/4/12.
//

#include <iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

/**
 * 将32位无符号整型反转
 * 《尾部数字弹出压入的方法》
 * @param x 32位无符号整型
 * @return 反转后的数字，如果溢出返回0
 */
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0; // 预判断：防止溢出
        rev = rev * 10 + pop;
    }
    return rev;
}

int main() {
    unsigned int a = -123;
    printf("%d\n", reverse(a));   // except：-321
    unsigned int b = 1534236469;
    printf("%d", reverse(b));   // except：0

}
