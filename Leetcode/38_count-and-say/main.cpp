//
// Created by kaide on 2021/4/23.
//
#include <string>

using namespace std;

/**
 * 外观数列
 * 《将数字字符串每小段计数》
 * @param n 第n项
 * @return 第n项外观数列
 */
string countAndSay(int n) {
    if (n == 1) {
        return "1";
    } else {
        string str = countAndSay(n - 1);
        int num = 0;
        string new_str;
        for (int i = 0; i < str.size(); i++) {
            if (i>0 && str[i-1] != str[i]) {
                new_str += to_string(num) + str[i - 1];
                num = 1;
            } else {
                num++;
            }
        }
        new_str += to_string(num) + str[str.size()-1];
        return new_str;
    }
}

int main(){
    string s = countAndSay(5);
    printf("%s\n", s.c_str());
}