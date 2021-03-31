// 189. 旋转数组
// Created by kaide on 2021/3/31.
//
#include <vector>

using namespace std;
/**
 * 使用临时数组，用取模的思想实现循环数组
 * 《使用额外的数组》
 * @param nums
 * @param k
 */
void rotate(vector<int>& nums, int k) {
    int length = nums.size();
    vector<int> tmp(length);

    int j;
    for (int i = 0; i < length; i++) {
        j = (i + k) % length;
        tmp[j] = nums[i];
    }
    nums = tmp;

}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    for(auto num:nums) {
        printf("%d,", num);     // expect: 5,6,7,1,2,3,4
    }

}