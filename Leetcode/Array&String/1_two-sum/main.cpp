#include <iostream>
#include <vector>
using namespace std;

/**
 * Topic1：给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标
 * 《暴力破解解法》
 * @param nums 整数数组
 * @param target 整数目标值
 * @return 数组下标
 */
vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[j] == target - nums[i]) {
                return {i, j};
            }
        }
    }
    return {};
}


int main() {
    // test1
    vector<int> nums1 = {2, 7 , 11, 15};
    vector<int> result1 = twoSum(nums1, 9);
    printf("[%d, %d]\n", result1[0], result1[1]);

    // test2
    vector<int> nums2 = {3,2,4};
    vector<int> result2 = twoSum(nums2, 6);
    printf("[%d, %d]\n", result2[0], result2[1]);

    // test3
    vector<int> nums3 = {3, 3};
    vector<int> result3 = twoSum(nums3, 6);
    printf("[%d, %d]\n", result3[0], result3[1]);
    return 0;
}
