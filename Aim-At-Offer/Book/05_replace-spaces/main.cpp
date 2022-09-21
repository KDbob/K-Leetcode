// 剑指 Offer 05. 替换空格
// Created by kaide on 2021/3/15.
//
#include <string>

using namespace std;
/**
 * Topic 05: 请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"
 * 《原地修改思想》
 * @param s 字符串
 * @return 修改后的字符串
 */
string replaceSpace(string s) {
    int length = s.size();
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    s.resize(length + 2 * count);
    for (int i = length - 1, j = length + 2 * count - 1; i < j ; ) {
        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
            i--;
        } else {
            s[j--] = s[i--];
        }
    }
    return s;
}

int main() {
    string s = "We are happy.";
    string result = replaceSpace(s);
    printf("result1 is:%s\n", result.c_str());

    string s2 = "     ";
    string result2 = replaceSpace(s2);
    printf("result2 is:%s\n", result2.c_str());
    return 0;
}