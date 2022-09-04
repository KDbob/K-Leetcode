// 3. 无重复字符的最长子串
// Created by bob on 2022/4/11.
//
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int k = 0; k < n; ++k) {
            if (k != 0) {
                set.erase(s[k - 1]);    // 滑动窗口上个起始的元素
            }
            while (rk + 1 < n && !set.count(s[rk + 1])) {
                set.insert(s[rk+1]);
                ++rk;
            }
            ans = max(ans, rk - k + 1);
        }
        return ans;
    }
};


int main() {
    string s = "abcabcbb";
    int result = Solution().lengthOfLongestSubstring(s);
    printf("%d", result);   // expect: 3
    return 0;
}