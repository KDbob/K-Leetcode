// 191. 位1的个数
// Created by kaide on 2021/3/22.
//

#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int res = 0;
    while (n) {
        n &= (n-1);
        res++;
    }
    return res;
}



int main(){
    uint32_t n = 127;   // 1111111
    int i = hammingWeight(n);   // expect：7
    printf("%d", i);
}