// 326. 3的幂
// Created by kaide on 2021/6/2.
//
#include <string>

using namespace std;

bool isPowerOfThree(int n) {
    string str = to_string(n);
//    char *p = "256";
//    int i = stoi(p,0,2);
    if (n % 10 == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    if (isPowerOfThree(27)) {
        printf("is power of three\n");
    } else {
        printf("not power of three\n");
    }
}