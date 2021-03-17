// 剑指 Offer 04. 二维数组中的查找
// Created by kaide on 2021/3/14.
//
#include <vector>

using namespace std;

/** Topic 04: 二维数组中的查找
 * 《从右上角开始查找版本》
 * @param matrix 矩阵
 * @param target 目标值
 * @return 是否匹配
 */
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) return false;  // 解决leetcode报错问题
    int j = matrix[0].size() - 1;
    int i = 0;
    while (i <= matrix.size() - 1 && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--;
        } else if (matrix[i][j] < target) {
            i++;
        }
    }
    return false;
}

/*
 * 同上：《从右上角开始查找版本》
 */
bool findNumberIn2DArray1(vector<vector<int>> &matrix, int target) {
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] > target) i--;
        else if (matrix[i][j] < target) j++;
        else return true;
    }
    return false;
}


int main() {
    vector<vector<int>> martrix1 = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    bool result1 = findNumberIn2DArray(martrix1, 0);
    printf("20 in martrix %d\n", result1);

    vector<vector<int>> martrix2 = {{-5}};
    bool result2 = findNumberIn2DArray(martrix2, -5);
    printf("20 in martrix %d", result2);
    return 0;
}