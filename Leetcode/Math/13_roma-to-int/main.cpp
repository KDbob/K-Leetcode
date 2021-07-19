// 13. 罗马数字转整数
// Created by kaide on 2021/6/3.
//
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> romaMap{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};

/**
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 《模拟法》
 * @param s 罗马数字
 * @return 对应的整数
 */
int romanToInt(string s) {
    int sum = 0;
    int rightVal = romaMap[s[s.length() - 1]];
    sum += rightVal;
    for (int i = s.length()-2; i >= 0 ; --i) {
        int currVal = romaMap[s[i]];
        if (currVal < rightVal) {
            sum -= currVal;
        } else {
            sum += currVal;
        }
        rightVal = currVal;
    }
    return sum;
}

int main() {
    printf("%d\n", romanToInt("III"));  // expect: 3
    printf("%d\n", romanToInt("LVIII"));  // expect: 58
    printf("%d\n", romanToInt("MCMXCIV"));  // expect: 1994
}