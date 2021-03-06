#### [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **不触动警报装置的情况下** ，一夜之内能够偷窃到的最高金额。

 

**示例 1：**

```
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**示例 2：**

```
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
```

# 解题思路

## 方法一：动态规划

> 偷窃的房间具有最优子结构

##### 假设

设dp[i]为0~i间房间，一夜之间能够窃取的最大金额

##### 初始状态（考虑只有一间和两间房）

- 假设只有一间房间，dp[0] = nums[0]
- 假设有两件房间，则dp[1] = max(nums[0], nums[1])

##### 如果超过两间房时，假设一共有k(k>2)间房，一共有两个选项：

1. 偷窃第k间房屋，那么就不能偷窃第k-1间房，偷窃的总金额为<u>前k-2间房的最高总金额</u>+第k间房间的总金额
2. 不能偷窃第k间房，总价值为前k-1间房屋的最高总金额

##### 转移方程

$dp[k] = max(dp[k-2]+nums[k],dp[k-1])\quad(k>2)$

初始条件：
$$
\left\{\begin{align}
& dp[0] = nums[0]\\
& dp[1] = max(nums[0],nums[1])
\end{align}\right.
$$

### 准备数据结构

想到可以用一个一维的数组来存储dp[k]的信息，可以用“滚动数组”的思维仅使用两个变量（优化）

`int dp_pre2 = dp[k-2]`：表示前k-2能窃取的最大金额

`int dp_pre1 = dp[k-1]`：表示前k-1能窃取的最大金额

### 算法流程

1. 设置初始条件
2. 从3间房间开始遍历
   - 计算当前数量的房间最大的总金额
   - 更新条件
3. 返回当前数量的房间能窃取的最大总金额

#### 代码实现

```C++
int rob(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    int dp_pre2 = nums[0];
    int dp_pre1 = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
        int dp = max(dp_pre2 + nums[i], dp_pre1);
        dp_pre2 = dp_pre1;
        dp_pre1 = dp;
    }
    return dp_pre1;
}
```

