//
// Created by bob on 2022/3/30.
//
#include<vector>
#include<string>
#include "KPrint.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, n, 0, 0);
        return result;
    }

    void backtrack(vector<string> &ans, string &cur, int n, int open, int close) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, n, open + 1, close);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, n, open, close + 1);
            cur.pop_back();
        }
    }
};

int main() {
    vector<string> res = Solution().generateParenthesis(3);
    printVector(res);       // expect: ((())), (()()), (())(), ()(()), ()()()
}