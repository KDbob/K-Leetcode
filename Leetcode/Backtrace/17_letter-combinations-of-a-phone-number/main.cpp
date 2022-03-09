// 17. 电话号码的字母组合
// Created by bob on 2022/3/8.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "KPrint.h"

using namespace std;

class Solution {
public:

    /**
     * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
     * @param digits 电话号码
     * @return 它能表示的字母组合
     */
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.length() == 0) return combinations;
        unordered_map<char, string> phoneMap{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        string combination;
        backtrack(phoneMap, digits, 0, combination, combinations);
        return combinations;
    }

    void backtrack(const unordered_map<char, string>& phoneMap, const string& digits,int index, string& combination, vector<string>& combinations) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char num = digits[index];
            const string& letters = phoneMap.at(num);
            for (auto letter:letters) {
                combination.push_back(letter);
                backtrack(phoneMap, digits, index + 1, combination, combinations);
                combination.pop_back(); // ★临时的string容器需要清空
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<string> vector = s.letterCombinations("23");
    printVector(vector);    // expect：ad, ae, af, bd, be, bf, cd, ce, cf
}