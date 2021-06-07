// 191. 位1的个数
// Created by kaide on 2021/3/22.
//

#include <iostream>
using namespace std;

/**
 * 输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数
 * 《方法一：循环检查二进制位数》
 * @param n 无符号整数
 * @return 数字位为'1'的个数
 */
int hammingWeight1(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        if(n & (1 << i)) {
            res++;
        }
    }
    return res;
}

/**
 * 输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数
 * 《方法二：位运算优化》
 * @param n 无符号整数
 * @return 数字位为'1'的个数
 */
int hammingWeight2(uint32_t n) {
    int res = 0;
    while (n) {
        n &= (n-1);
        res++;
    }
    return res;
}



int main(){
    uint32_t n1 = 10;   // 1010
    printf("%d\n", hammingWeight2(n1)); // expect：2

    uint32_t n2 = 127;   // 1111111
    int i = hammingWeight2(n2);   // expect：7
    printf("%d\n", i);
}