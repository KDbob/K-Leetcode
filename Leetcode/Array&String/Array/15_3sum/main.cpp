//
// Created by bob on 2022/3/14.
//
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 先进行排序
    vector<vector<int>> ans;
    for (int first = 0; first < n; first++) {
        if (first >0 && nums[first] == nums[first-1]) {
            continue;
        }
        int third = n - 1;
        int target = -nums[first];
        for (int second = first + 1; second < n; ++second) {
            if (second > first + 1 && nums[second] == nums[second-1]) {     // 需要和上一次枚举的数不相同
                continue;
            }
            while (second < third && nums[second] + nums[third] > target) { // 不等式的一个变形
                third--;
            }
            if (second == third) {  // b=c时，不能满足不重复条件，提前结束循环
                break;
            }
            if (nums[first] + nums[second] + nums[third] == 0) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, - 1, -4};
    Solution s = Solution();
    vector<vector<int>> result = s.threeSum(nums);  // expect：[[-1,-1,2],[-1,0,1]]
    return 0;
}