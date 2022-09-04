// 2352. 相等行列对
// Created by bob on 2022/7/28.
//
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<string, int> cntMap;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            string s = "";
            for (int j = 0; j < m; ++j) {
                s += to_string(grid[i][j]);
                s += " ";
            }
            cntMap[s]++;
        }

        for (int i = 0; i < m; ++i) {
            string s = "";
            for (int j = 0; j < m; ++j) {
                s += to_string(grid[j][i]);
                s += " ";
            }
            if (cntMap.count(s)) {
                ans += cntMap[s];
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{3, 1, 2, 2},
                                {1, 4, 4, 5},
                                {2, 4, 2, 2},
                                {2, 4, 2, 2}};
    int res = Solution().equalPairs(grid);
    printf("%d", res);  // expect: 3
    return 0;
}