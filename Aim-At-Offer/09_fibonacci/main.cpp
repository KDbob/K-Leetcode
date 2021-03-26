// 剑指 Offer 10- I. 斐波那契数列
// Created by kaide on 2021/3/24.
//
#include <iostream>
using namespace std;

/**
 * 获得第n位fibonacci数
 * 《动态规划法》
 * @param n 第n位
 * @return 第n位fibonacci数
 */
int fib(int n) {
    int a = 0, b = 1, sum;
    for (int i = 0; i < n; i++) {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}

int main() {
    int res1 = fib(2);
    printf("%d\n", res1);  // expect:1
    
    int res2 = fib(5);  // expect:5
    printf("%d\n", res2);

    int res3 = fib(45); // expect:134903163
    printf("%d\n", res3);
}