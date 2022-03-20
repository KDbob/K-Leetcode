//
// Created by bob on 2022/3/17.
//
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
     * 《回溯法》
     * @param board m x n 的二维字符网格
     * @param word 字符串单词
     * @return word是否存在于网格中
     */
    bool exist(vector<vector<char>> &board, string word) {
        int h = board.size();
        int w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                bool falg = check(visited, board, word, i, j, 0);
                if (falg) return true;
            }
        }
        return false;
    }

    /**
     * 递归子算法：递归检查该位置的字母是否和目标单词相同
     * @param visited 临时变量，标志是否被访问过
     * @param k 递归深度
     * @return
     */
    bool check(vector<vector<int>> &visited, vector<vector<char>> &board, string &word, int i, int j, int k) {
        if (board[i][j] != word[k]) {
            return false;
        } else if (k == word.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        bool result = false;
        vector<pair<int, int>> directions{{0,  1},{1,  0},{-1, 0},{0,  -1}};
        for (auto dir: directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (visited[newi][newj] == false) {
                    bool flag = check(visited, board, word, newi, newj, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";
    Solution s = Solution();
    bool flag = s.exist(board, word);
    if (flag) {
        printf("true");     // expect: true
    } else {
        printf("false");
    }
    return 0;

}