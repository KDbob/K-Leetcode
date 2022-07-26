// 78. 子集
// Created by bob on 2022/4/17.
//
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, 0, result, current);
        return result;
    }

    void dfs(vector<int>& nums, int t, vector<vector<int>> &result, vector<int> &cur) {
        if (t == nums.size()) {
            result.push_back(cur);
        } else {
            cur.push_back(nums[t]);
            dfs(nums, t + 1, result, cur);  // 可以选择加入
            cur.pop_back();
            dfs(nums, t + 1, result, cur);  // 也可以选择不加入
        }
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            current.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    current.push_back(nums[i]);
                }
            }
            result.push_back(current);
        }
        return result;
    }


};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().subsets(nums);
    vector<vector<int>> res2 = Solution().subsets2(nums);
    return 0;
}