// 36. 有效的数独
// Created by kaide on 2021/4/6.
//
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 检查是否是正确的数独
 * 《使用hash表检查单元格存在的次数》
 * @param board 数独二维数组
 * @return True or false
 */
bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, int> rows_map[9];
    unordered_map<int, int> cols_map[9];
    unordered_map<int, int> boxes_map[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                int num = (int) c;
                rows_map[i][num]++;
                if (rows_map[i][num] > 1) {
                    return false;
                }
                cols_map[j][num]++;
                if (cols_map[j][num] > 1) {
                    return false;
                }
                int boxIdx = (i / 3) * 3 + j / 3;
                boxes_map[boxIdx][num]++;
                if (boxes_map[boxIdx][num] > 1) {
                    return false;
                }
            }
        }

    }
    return true;
}

int main() {
    vector<vector<char>> board = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if (isValidSudoku(board)) {
        printf("true");
    } else {
        printf("false");    // except:false
    }

}