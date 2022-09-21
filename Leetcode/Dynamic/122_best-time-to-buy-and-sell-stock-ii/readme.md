#### [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

给定一个数组 `prices` ，其中 `prices[i]` 是一支给定股票第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
```

**示例 2:**

```
输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3:**

```
输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

# 解题思路

## 方法一：动态规划

#### 动态规划详解

> 当问题的最优解包含了其子问题的最优解时，称该问题具有最优子结构性质。可以分析出最优子结构性质如下：

##### 考虑利润

持有股票的时候，资产应该是负的（空仓情况下，假设第j天买入股票，当天交易完的利润应该是$-prices[j]$）

只有卖出股票时，利润才是正的（在第j天买入股票，在第i天(i>j)卖出股票，当天交易完成的利润应该是$-prices[j]+prices[i]$）

##### 定义

- 定义$dp[i][0]$表示第i天交易完后，手里没有股票的最大利润
- 定义$dp[i][1]$表示第i天交易完后，手里持有一只股票的最大利润

##### 思考转移状态

1. 考虑$dp[i][0]$的转移方程

   > 如果这一天交易后手里已经没有股票，有两种情况

   - 昨天(第i-1天)手上也没有股票，即：$dp[i-1][0]$
   - 昨天手上本来有股票，但是今天卖了。即：$dp[i-1][1]+prices[i]$

   为了利益最大化，应该满足如下方程（最优子结构性质）：$dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])$

2. 考虑$dp[i][1]的转移方程$

   > 如果这一天交易后手里持有一支股票，有两种情况

   - 昨天本来来没有股票，但是今天买了，即：$dp[i-1][0]-prices[i]$
   - 昨天就持有股票，即：$dp[i-1][1]$

   为了利益最大化，应该满足如下方程（最优子结构性质）：$dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])$

##### 考虑初始情况

$dp[0][0]=0$

$dp[0][1]=-prices$

#### 准备数据结构

（优化）因为每天的状态只与前一天的状态有关，因此可以用三个不断更新的变量代替一维数组的数据结构。

`int dp0 = dp[i-1][0]`

> 表示前一天手里没有股票的最大利润

`int dp1 = dp[i-1][1]`

> 表示前一手里有股票的最大利润

#### 算法流程

1. 初始化dp0和dp1
2. 遍历每日股票价格
   - 计算今日交易后手里没有股票的最大利润：$dp[i][0]$
   - 计算今日交易后手里还持有股票的最大利润：$dp[i][1]$
   - 更新两个临时变量dp0和dp1的值

3. 遍历结束，返回今日交易后手里没有持有股票的最大利润：$dp[i][0]$

#### 代码实现

```C++
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
```
