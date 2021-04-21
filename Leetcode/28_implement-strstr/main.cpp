// 28. 实现 strStr()
// Created by kaide on 2021/4/21.
//
#include <string>

using namespace std;

/**
 * 实现 strStr() 函数
 * 《简单匹配法》
 * @param haystack 主串
 * @param needle 子串
 * @return 匹配的字符串在主串出现的第一个位置
 */
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    int i = 0, j = 0;
    bool flag = false;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            flag = true;
        } else {
            if (flag) {
                i = i - j + 1;
                flag = false;
            } else {
                i++;
            }
            j = 0;
        }
    }
    if (j == needle.size()) {
        return i - j;
    } else {
        return -1;
    }
}

int main(){
//    string haystack = "hello", needle = "l";
    string haystack = "ippi", needle = "pi";
    int i = strStr(haystack, needle);
    printf("%d\n", i);
}

