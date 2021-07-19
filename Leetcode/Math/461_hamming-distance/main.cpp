// 461. 汉明距离
// Created by kaide on 2021/6/7.
//
#include<iostream>

using namespace std;

int hammingDistance1(int x, int y) {
    return __builtin_popcount(x ^ y);
}

int hammingDistance2(int x, int y) {
    int s = x ^y;
    int res = 0;
    while (s) {
        if (s&1) {
            res++;
        }
        s = s >> 1;
    }
    return res;
}

int hammingDistance3(int x, int y) {
    int s = x ^y;
    int res = 0;
    while (s) {
        res++;
        s = s & (s - 1);
    }
    return res;
}



int main() {
    printf("haming distance is %d \n", hammingDistance1(1, 4));  // expect: 2
    printf("haming distance is %d \n", hammingDistance2(1, 4));
    printf("haming distance is %d \n", hammingDistance3(1, 4));
}