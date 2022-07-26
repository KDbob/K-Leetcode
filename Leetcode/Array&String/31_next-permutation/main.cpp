// 31. 下一个排列
// Created by bob on 2022/6/16.
//

#include<vector>
#include "KPrint.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i>=0 && nums[i-1] >= nums[i]) {
            i--;
        }
        if (i >=0) {
            int j = nums.size() - 1;
            while (j>=0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution().nextPermutation(nums);
    printVector(nums);
}