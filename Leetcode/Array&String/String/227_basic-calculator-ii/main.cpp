//
// Created by kaide on 2021/3/12.
//
#include <string>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Topic 227: 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 整数除法仅保留整数部分。
 * 《利用栈的思想》
 * @param s 字符串表达式s
 * @return 计算器的返回值
 */
int calculate(string s) {
    vector<int> stack;
    char presign = '+';
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + int(c - '0');
        }
        if (!isdigit(c) && c != ' ' || i == s.length() - 1) {
            switch (presign) {
                case '+':
                    stack.push_back(+num);
                    break;
                case '-':
                    stack.push_back(-num);
                    break;
                case '*':
                    stack.back() *= num;
                    break;
                case '/':
                    stack.back() /= num;
                    break;
            }
            presign = c;
            num = 0;
        }
    }
    return accumulate(stack.begin(), stack.end(), 0);
}

int main() {
    string string1 = "3+2*2";
    int result1 = calculate(string1);
    printf("%d\n", result1);
//
//    string string2 = " 3/2 ";
//    int result2 = calculate(string2);
//    printf("%d\n", result2);
//
//    string string3 = "42";
//    int result3 = calculate(string3);
//    printf("%d\n", result3);

    string string4 = "3+2*2-5/2";
    int result4 = calculate(string4);
    printf("%d\n", result4);
    return 0;
}