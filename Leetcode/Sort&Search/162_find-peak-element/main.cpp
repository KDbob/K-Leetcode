// 162. 寻找峰值
// Created by bob on 2022/5/15.
//
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        int idx = rand() % n;
        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) {
                return {0, 0};
            }
            return {1, nums[i]};
        };
        while (!(get(idx-1) < get(idx) && get(idx) > get(idx + 1))) {
            if (get(idx) < get(idx + 1)) {
                idx += 1;
            } else {
                idx -= 1;
            }
        }
        return idx;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int res = Solution().findPeakElement(nums);
    printf("%d", res);
}