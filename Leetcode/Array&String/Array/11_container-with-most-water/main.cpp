// 11. 盛最多水的容器
// Created by bob on 2022/4/21.
//
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int sum = min(height[l], height[r]) * (r - l);
            ans = max(sum, ans);
            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = Solution().maxArea(nums); // expect: 49
}