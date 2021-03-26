// 剑指 Offer 10- II. 青蛙跳台阶问题
// Created by kaide on 2021/3/26.
//
#include <iostream>

/**
 *  将f(n)的方案数存在公式：f(n) = f(n-1) + f(n-2)
 *  《递归方法》类似fibonacci
 * @param n 台阶数
 * @return 方案数
 */
int numWays_rec(int n){
    if (n > 0) {
        if (n==1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            return numWays_rec(n - 1) + numWays_rec(n - 2);
        }
    }
}

/**
 *  将f(n)的方案数存在公式：f(n) = f(n-1) + f(n-2)
 *  《动态规划法》类似fibonacci
 * @param n 台阶数
 * @return 方案数
 */
int numWays(int n){
    int a = 1, b = 1, sum;
    for (int i = 0; i < n; i++) {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}



int main(){
    // 测试递归方法（主要理解思想）
    int test1 = numWays_rec(7);
    printf("%d\n", test1);  // expect:21

    int test2 = numWays(7); // expect:21
    printf("%d\n", test2);
}


