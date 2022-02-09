//
// Created by bob on 2022/2/8.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    /**
     * DFS算法，岛屿数量的子算法
     * @param grid 二维数组
     * @param r 遍历该顶点的横坐标
     * @param c 遍历该顶点的纵坐标
     */
    void dfs(vector<vector<char>> &grid, int r, int c) {
        int rLen = grid.size();
        int cLen = grid[0].size();
        grid[r][c] = '0';   // 将遍历过的值修改为0
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < rLen && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < cLen && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

public:
    /**
     * 岛屿数量
     * @param grid 二维数组
     * @return 岛屿的数量
     */
    int numIslands(vector<vector<char>> &grid) {
        int rLen = grid.size();
        int cLen = grid[0].size();
        int sum = 0; 
        for (int r = 0; r < rLen; ++r) {
            for (int c = 0; c < cLen; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    sum += 1;
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    Solution s = Solution();
    int num = s.numIslands(grid);
    printf("%d", num);  // expect: 3
}