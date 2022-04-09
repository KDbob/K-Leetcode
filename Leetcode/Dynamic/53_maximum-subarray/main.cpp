// 53. 最大子序和
// Created by kaide on 2021/5/25.
//
#include <vector>

using namespace std;

/**
 * 53. 最大子序和
 * 《动态规划》
 * @param nums 整数数组
 * @return 连续子数组（子数组最少包含一个元素）的最大和
 */
int maxSubArray(vector<int> &nums) {
    int f_pre = nums[0];
    int f_max = f_pre;
    for (int i = 1; i < nums.size(); i++) {
        f_pre = max(nums[i], f_pre + nums[i]);
        f_max = max(f_max, f_pre);
    }
    return f_max;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("max sum of subarray is %d\n", maxSubArray(nums));

    vector<int> nums1 = {5, 4, -1, 7, 8};
    printf("max sum of subarray is %d\n", maxSubArray(nums1));
}