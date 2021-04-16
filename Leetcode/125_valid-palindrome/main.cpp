// 125. 验证回文串
// Created by kaide on 2021/4/16.
//
#include <string>

using namespace std;

/**
 * 给定一个字符串，验证它是否是回文串
 * 《处理字符串后使用双指针法》
 * @param s 字符串
 * @return 是否是回文串
 */
bool isPalindrome(string s) {
    string sgood;
    for (auto ch:s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    int l = 0, r = sgood.size()-1;
    while (l < r) {
        if (sgood[l++] != sgood[r--] ) return false;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        printf("isPalindrome\n");
    } else {
        printf("not Palindrome\n");
    }
}