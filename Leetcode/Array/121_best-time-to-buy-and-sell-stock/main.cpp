// 121. 买卖股票的最佳时机
// Created by kaide on 2021/5/23.
//
#include <vector>
#define INT_MAX 2147483647
using namespace std;


/**
 * 只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 《单次遍历》
 * @param prices 它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * @return 从这笔交易中获取的最大利润
 */
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (auto price:prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    printf("max porfit is %d", maxProfit(prices));  // except: 5

}