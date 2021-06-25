//
// Created by kaide on 2021/6/16.
//
#include <vector>

using namespace std;

/**
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * @param numRows 输入行数
 * @return 杨辉三角的前numRows行
 */
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret(numRows);
    for (int i = 0; i < numRows; i++) {
        vector<int> tmp(i+1);
        tmp[0] = tmp[i] = 1;
        for (int j = 1; j < i; j++) {
            tmp[j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        ret[i] = tmp;
    }
    return ret;
}

int main() {
    vector<vector<int>> ret = generate(5);
    for (auto v:ret) {
        for (auto n:v) {
            printf("%d,", n);
        }
        printf("\n");
    }
}