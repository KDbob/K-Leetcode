// 20. 有效的括号
// Created by kaide on 2021/6/25.
//
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, char> pairs = {
        {'}', '{'},
        {')', '('},
        {']', '['},
};

/**
 * 给定一个只包括括号的字符串 `s` ，判断字符串是否有效
 * 《方法一：栈匹配》
 * @param s 只包含括号的字符串
 * @return 字符串是否有效
 */
bool isValid(string s) {
    stack<char> stk;
    if (s.size() % 2 == 1) return false;
    for (int i=0; i < s.size(); i++) {
        if (!pairs.count(s[i])) {  // 等价于 if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            stk.push(s[i]);
        } else if (!stk.empty() && pairs[s[i]] == stk.top()){
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}

void test(string s) {
    if (isValid(s)) {
        printf("is valid string\n");
    } else {
        printf("invalid string\n");
    }
}


int main() {
    string s1 = "{[]}";
    test(s1);       // expect: valid
    string s2 = "]";
    test(s2);       // expect: invalid
    string s3 = "){";
    test(s3);       // expect: invalid
}