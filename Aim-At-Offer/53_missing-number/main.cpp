// 剑指 Offer 53 - II. 0～n-1中缺失的数字
// Created by kaide on 2021/6/27.
//
#include <vector>

using namespace std;

/**
 * 缺失的数字
 * 《利用异或性质⊕》
 * @param nums
 * @return
 */
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = n;
    for (int i=0; i < n; i++) {
        res = nums[i] ^ i ^ res;
    }
    return res;
}

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    printf("%d", missingNumber(nums));  // expect: 8
}