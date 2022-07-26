//  39. 组合总和
// Created by bob on 2022/6/20.
//
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, result, current);
        return result;
    }

    void dfs(vector<int>& nums, int target, int idx, vector<vector<int>> &result, vector<int> &cur) {
        if (idx == nums.size()) {
            return;
        }
        if (target == 0) {
            result.push_back(cur);
            return;
        }
        // 直接跳过
        dfs(nums, target, idx + 1, result, cur);
        // 选择当前数
        if (target - nums[idx] >= 0) {
            cur.push_back(nums[idx]);
            dfs(nums, target - nums[idx], idx, result, cur);
            cur.pop_back();
        }

    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = Solution().combinationSum(candidates, target);
    return 0;
}