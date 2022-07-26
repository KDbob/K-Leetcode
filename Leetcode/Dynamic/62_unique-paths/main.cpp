// 62. 不同路径
// Created by bob on 2022/6/23.
//
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tmp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            tmp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            tmp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                tmp[i][j] = tmp[i - 1][j] + tmp[i][j - 1];
            }
        }
        return tmp[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7;
    int result = Solution().uniquePaths(m, n);
    printf("%d", result);   // expect: 28
    return 0;
}