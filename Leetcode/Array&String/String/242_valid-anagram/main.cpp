// 242. 有效的字母异位词
// Created by kaide on 2021/4/15.
//
#include <string>
#include <vector>
using namespace std;

/**
 * 判断是否有效的字母异位词
 * 《hash表的判断思想》
 * @param s 字符串1
 * @param t 字符串2
 * @return 是否
 */
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> mp(26, 0);
    for(auto ch:s) {
        mp[ch - 'a']++;
    }
    for(auto ch:t) {
        mp[ch - 'a']--;
        if (mp[ch - 'a'] < 0) {
            return false;
        }
    }
    return true;
}





int main() {
//    string s = "anagram", t = "nagaram";
    string s = "car", t = "rat";
    if (isAnagram(s,t)) {
        printf("isAnagrame\n");
    } else {
        printf("not anagrame");
    }
}