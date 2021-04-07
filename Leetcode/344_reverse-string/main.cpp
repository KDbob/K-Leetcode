// 344. 反转字符串
// Created by kaide on 2021/4/7.
//
#include <vector>

using namespace std;

/**
 * 反转字符串
 * 《双指针交换值》
 * @param s 反转后的字符串
 */
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
}

int main(){
    vector<char> str{'h', 'e', 'l', 'l', 'o'};
    reverseString(str);
    for (auto s:str) {
        printf("%c,", s);
    }
    
}