// 240. 搜索二维矩阵 II
// Created by bob on 2022/5/13.
//
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        while (x < m && y >=0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};


int main(){
    vector<vector<int>> matrix = {{1,  4,  7,  11, 15},
                                  {2,  5,  8,  12, 19},
                                  {3,  6,  9,  16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;
    bool res = Solution().searchMatrix(matrix, target);
    if (res) {
        printf("true");     // expect:true
    } else {
        printf("false");
    }

}