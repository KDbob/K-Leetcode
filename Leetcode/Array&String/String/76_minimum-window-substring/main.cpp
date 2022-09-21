// 76. 最小覆盖子串
// Created by bob on 2022/9/6.
//
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check() {
        for (auto &p:ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (auto &c: t) {
            ori[c]++;
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;
        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                cnt[s[r]]++;
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r- l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    cnt[s[l]]--;
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = Solution().minWindow(s, t);
    printf("%s", res.c_str());
    return 0;
}