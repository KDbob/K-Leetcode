// 46. 全排列
// Created by bob on 2022/3/9.
//

#include<vector>

using namespace std;


class Solution {
public:
    /**
     * 给定一个不含重复数字的数组 nums ，返回其所有可能的全排列
     * @param nums 不含重复数字的数组
     * @return 所有可能的全排列
     */
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> permutes;
        if (nums.size() == 0) return permutes;
        vector<int> permite;
        backtrace(nums, 0, permutes, permite);
        return permutes;
    }

    /**
     * 值是否存在于数组中
     * @param picks 数组
     * @param num 值
     * @return 如果存在返回False，否则返回True
     */
    bool pickCheck(vector<int> &picks,int num) {
        if (picks.size() == 0) return true;
        for (auto pick : picks) {
            if (pick == num) {
                return false;
            }
        }
        return true;
    }

    void backtrace(vector<int> &nums, int index, vector<vector<int>> &permutes, vector<int> &permite) {
        if (index == nums.size()) {
            permutes.push_back(permite);
        } else {
            for (auto num: nums) {
                if (pickCheck(permite,num)) {
                    permite.push_back(num);
                    backtrace(nums, index + 1, permutes, permite);
                    permite.pop_back();
                }
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s = Solution();
    vector<vector<int>> results = s.permute(nums);  // expect like: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
    return 0;
}