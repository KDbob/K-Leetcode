// 26. 删除有序数组中的重复项
// Created by kaide on 2021/3/29.
//
#include <vector>

using namespace std;
/**
 * 删除有序数组中的重复项，并返回删除重复项后数组长度
 * 《双指针》
 * @param nums 有序数组
 * @return 删除重复项后数组长度
 */
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i =0;
    for (int j=0; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int i = removeDuplicates(nums);
    printf("%d", i);    // expect: 5
}