// 14. 最长公共前缀
// Created by kaide on 2021/4/24.
//
#include <string>
#include <vector>

using namespace std;

/**
 * 查找字符串数组中的最长公共前缀
 * 《纵向扫描法》
 * @param strs 需要查找的字符串
 * @return 最长公共前缀
 */
string longestCommonPrefix(vector<string>& strs) {
    string fir_str = strs[0];
    int fir_len = strs[0].length();
    for (int i = 0; i < fir_len; ++i) {
        char ch = fir_str[i];
        for (int j = 1; j < strs.size(); ++j) {
            string str = strs[j];
            if (i == fir_len || ch != str[i]) {
                return fir_str.substr(0, i);
            }
        }
    }
    return fir_str;
}

int main(){
    vector<string> strs= {"flower", "flow", "flight"};
    string res = longestCommonPrefix(strs);
    printf("%s", res.c_str());
}