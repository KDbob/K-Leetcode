// 14. 最长公共前缀
// Created by kaide on 2021/4/24.
//
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string fir_str = strs[0];
    int fir_len = strs[0].length();
    for (int i = 0; i < fir_str.length(); ++i) {
        char ch = fir_str[i];
        for (int j = 1; j < strs.size(); ++j) {
            string str = strs[j];
            if (str.length() <= fir_len && ch == str[i]) {

            } else {
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