// 74. 搜索二维矩阵
// Created by bob on 2021/8/9.
//
#include "vector"

using namespace std;

/**
 * 子算法：二分查找搜索第一列元素
 * @param matrix 二维矩阵
 * @param target 目标值
 * @return 目标值所在的row下标，如果没有则为0
 */
int binarySearchFirstColumn(vector<vector<int>> &matrix, int target) {
    int low = -1;
    int high = matrix.size() - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (matrix[mid][0] <= target) {
            // 缩小范围：[mid, high]
            low = mid;
        } else {
            // 缩小范围：[low, mid-1]
            high = mid - 1;
        }
    }
    return low;
}

/**
 * 子算法：二分查找搜索行中的元素
 * @param row 当前行
 * @param target 目标值
 * @return 找到则true，否则false
 */
bool binarySearchRow(vector<int> row, int target) {
    int low = 0;
    int high = row.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] == target) return true;
        if (row[mid] < target) {
            // 缩小范围：[mid+1, high]
            low = mid + 1;
        } else {
            // 缩小范围：[low, mid-1]
            high = mid - 1;
        }
    }
    return false;
}


/** 编写一个高效的算法来判断m x n矩阵中，是否存在一个目标值。该矩阵具有如下特性：

    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。

 * 《两次二分查找法》
 * @param matrix mx
 * @param target
 * @return
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rowIndex = binarySearchFirstColumn(matrix, target);
    if (rowIndex < 0) return false;
    return binarySearchRow(matrix[rowIndex], target);
}


/*--------------------------------------test func--------------------------------------------*/


int main() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    if (searchMatrix(matrix, -1)) {
        printf("true\n");   // expect: true
    } else {
        printf("false\n");
    }

    if (searchMatrix(matrix, 13)) {
        printf("true\n");
    } else {
        printf("false\n");  // expect: false
    }

    // TODO：一次二分查找
}