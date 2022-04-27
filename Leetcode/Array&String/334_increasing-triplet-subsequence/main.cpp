// 334. 递增的三元子序列
// Created by bob on 2022/4/14.
//
#include <vector>

#define INT_MAX 2147483647

using namespace std;

class Solution {
public:
    /**  给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
     *  《借助辅助数组》
     * @param nums 整数数组 nums
     * @return 是否存在长度为 3 的递增子序列
     */
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n ; ++i) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int j = n-2; j >= 0 ; --j) {
            rightMax[j] = max(rightMax[j + 1], nums[j]);
        }
        for (int k = 1; k < n -1 ; ++k) {
            if (leftMin[k] < nums[k] && nums[k] < rightMax[k]) {
                return true;
            }
        }
        return false;
    }

    /**
     * 《贪心算法》
     * @param nums
     * @return
     */
    bool increasingTriplet2(vector<int> & nums) {
        int n = nums.size();
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > second) {
                return true;
            } else if (nums[i] > first) {
                second = nums[i];
            } else {
                first = nums[i];
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2, 4, -2, -3};
    bool res = Solution().increasingTriplet(nums);
    if (res) {
        printf("true");
    } else {
        printf("false");
    }

    vector<int> nums2 = {0,4,2,1,0,-1,-3};
    bool res2 = Solution().increasingTriplet2(nums2);
    if (res2) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}