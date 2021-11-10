// 73. 矩阵置零
// Created by bob on 2021/11/10.
//
#include <vector>

using namespace std;

/**
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法
 * O(m + n) 的额外空间：《使用标记数组法》
 * @param matrix
 */
void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m), col(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}


void print2DArray(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/*--------------------------------------test func--------------------------------------------*/
int main() {
    vector<vector<int>> matrix1 = {{1, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 1}};
    setZeroes(matrix1);
    print2DArray(matrix1);
    printf("\n");

    vector<vector<int>> matrix2 = {{1, 1, 2, 0},
                                   {3, 4, 5, 2},
                                   {1, 3, 1, 5}};
    setZeroes(matrix2);
    print2DArray(matrix2);
}