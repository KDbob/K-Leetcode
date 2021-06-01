// 204. 计数质数
// Created by kaide on 2021/6/1.
//
#include <iostream>
#include <vector>

using namespace std;


bool isPrime(int num) {
    for (int i=2; i * i <=num; i++) {
        // 程序隐含了: 2和3本身是质数，但是不满足<sqrt(i),所以不会进入循环体内
        if (num % i==0) return false;
    }
    return true;
}

/**
 * 统计所有小于非负整数 n 的质数的数量。
 * 《方法一：枚举法》
 * @param n 非负整数
 * @return 质数的总数
 */
int countPrimes1(int n) {
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)){
            sum++;
        }
    }
    return sum;
}

/**
 * 统计所有小于非负整数 n 的质数的数量。
 * 《方法二：》
 * @param n 非负整数
 * @return 质数的总数
 */
int countPrimes2(int n) {
    vector<bool> isPrimeArr(n, true);
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrimeArr[i]) {
            sum++;
            if ((long long) i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrimeArr[j] = false;
                }
            }
        }
    }
    return sum;
}



int main() {
//    isPrime(2);
    printf("total prime num is %d\n", countPrimes1(10));     // expect: 4
    printf("total prime num is %d\n", countPrimes2(100));     // expect: 25

}