// 49. 字母异位词分组
// Created by bob on 2022/4/22.
//
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string &str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it=mp.begin(); it!=mp.end();it ++) {
        ans.emplace_back(it->second);
    }
    return ans;
}
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);    // expect: [["bat"],["nat","tan"],["ate","eat","tea"]]
    return 0;
}