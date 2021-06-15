// 190. 颠倒二进制位
// Created by kaide on 2021/6/15.
//
#include <iostream>

using namespace std;

/**
 * 颠倒给定的 32 位无符号整数的二进制位
 * 《方法一：逐位颠倒》
 * @param n 32 位无符号整数
 * @return 按二进制位颠倒后的无符号整数
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n = n >> 1;
    }
    return rev;
}

int main() {
    uint32_t n1 = 43261596;
    printf("%d\n", reverseBits(n1));    // expect: 964176192
}