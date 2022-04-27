// 5. 最长回文子串
// Created by bob on 2022/4/19.
//
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // 先枚举子串长度
        for (int L = 2; L <= n; ++L) {
            // 枚举左边界
            for (int i = 0; i < n; ++i) {
                int j = L + i - 1; // 右边界
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {    // 最小情况
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 统计最大长度
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }

            }

        }
        return s.substr(begin, maxlen);
    }
};

int main() {
    string s = "babad";
    string res = Solution().longestPalindrome(s);
    printf("%s", res.c_str());     // expect: bab
}