// 122. 买卖股票的最佳时机 II
// Created by kaide on 2021/5/24.
//
#include <vector>

using namespace std;

/**
 * 计算你所能获取的最大利润。你可以尽可能地完成更多的交易
 * 《动态规划法》
 * @param prices 是一支给定股票第 i 天的价格
 * @return 能获取的最大利润
 */
int maxProfit(vector<int>& prices) {
    int dp0 = 0;
    int dp1 = -prices[0];
    for (int i = 1; i <prices.size() ; ++i) {
        int d0 = max(dp0, dp1 + prices[i]);
        int d1 = max(dp1, dp0 - prices[i]);
        dp0 = d0;
        dp1 = d1;
    }
    return dp0;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    printf("max profit is %d\n", maxProfit(prices));    // expect: 7
}