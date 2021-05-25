// 198. 打家劫舍
// Created by kaide on 2021/5/25.
//
#include <vector>

using namespace std;

/** 计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
 * 《动态规划》
 * @param nums 每间房间的金额
 * @return 一夜之内能够偷窃到的最高金额
 */
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

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    printf("max price is %d/n", rob(nums)); // expect:12
}