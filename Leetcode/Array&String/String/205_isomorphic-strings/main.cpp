// 205. 同构字符串
// Created by bob on 2022/8/2.
//
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};

int main() {
    string s = "egg";
    string t = "add";
    bool res = Solution().isIsomorphic(s, t);
    if (res) {
        printf("true");     //  expect: true
    } else {
        printf("false");
    }
    return 0;
}