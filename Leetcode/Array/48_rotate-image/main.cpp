// 48. 旋转图像
// Created by kaide on 2021/4/6.
//
#include <vector>

using namespace std;

/**
 * 旋转数组
 * 《用一个辅助的矩阵的映射方法》
 * @param matrix 旋转后的数组
 */
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> matrix_new(matrix);
    for (int i=0;i< n; i++) {
        for (int j = 0; j < n; ++j) {
            matrix_new[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = matrix_new;
}

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            printf("%d,", matrix[i][j]);    // except: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
        }
        printf("\n");
    }
}