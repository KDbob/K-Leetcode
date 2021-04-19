// 67.字符串转换整数 (atoi)
// Created by kaide on 2021/4/19.
//
#include <string>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int myAtoi(string s) {
    int symbol = 1;
    int res = 0;
    int i = 0;
    while (s[i] == ' ') i++;    // 处理空格
    if (s[i] == '-') {
        symbol = -1;
        i++;
    } else if(s[i] == '+') {
        symbol = 1;
        i++;
    }
    for (; i < s.size(); ++i) {
        char x = s[i];
        if (isdigit(x)) {
            int n = x - '0';
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && n > 7)){
            return symbol==1? INT_MAX : INT_MIN;
        }
            res = res * 10 + n;
        } else {
            break;    // 如果不是数字，则跳出循环
        }
    }
    return res * symbol;
}

int main() {
//    string s = "4193 with words";
    string s = "-91283472332";
//    string s = "words and 987"; // expect: 0
//    string s = "+-12";  // expect: 0
//    string s = "   -42";
//    string s = "21474836460";
//    string s = "2147483647";
//    string s = "-2147483648";
    int i = myAtoi(s);
    printf("%d", i);
}