//
// Created by kaide on 2021/4/13.
//
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    queue<pair<char, int>> q;
    for (int i = 0; i < s.size(); ++i) {
        if (!mp.count(s[i])) {  // 如果该字母第一次出现
            mp[s[i]] = i;
            q.emplace(s[i], i);
        } else {
            mp[s[i]] = -1;
            while (!q.empty() && mp[q.front().first] == -1) {  // 说明有个出现第二次的字母
                q.pop();
            }
        }
    }
    return q.empty() ? -1 : q.front().second;
}

int main() {
//    string s = "leetcode";
//    printf("%d\n", firstUniqChar(s));
    string s1 = "loveleetcode";
    printf("%d\n", firstUniqChar(s1));
    string s2 = "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb";
    printf("%d\n", firstUniqChar(s2));
}