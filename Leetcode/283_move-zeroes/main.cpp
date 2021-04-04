// 283. 移动零
// Created by kaide on 2021/4/4.
//
#include <vector>

using namespace std;

/**
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * @param nums 数组nums
 */
void moveZeroes(vector<int> &nums) {
    int i = 0;
    while (i <nums.size() && nums[i] != 0) i++; // 找到第一个0元素
    int j = i +1;
    while (j < nums.size() && nums[j] == 0) j++;// 找到0元素后的第一个非0元素
    while (j < nums.size()) {
        int tem = nums[i];
        nums[i] = nums[j];
        nums[j] = tem;
        j +=1;
                //        while (i <nums.size() && nums[i] != 0) i++;  等价于 i+=1;
        i +=1;  // 此处num[i+1]一定是0，因为要么是i+1本身就是0，要么是j指向的是i+1,刚好交换了值。
        while (j < nums.size() && nums[j] == 0) j++;    // 找到之后的第一个非0元素
    }
}

int main() {
    vector<int> nums{1, 2, 0, 4, 3, 0, 0};
    moveZeroes(nums);
    for (auto num:nums) {
        printf("%d,", num);     //expect: 1, 2, 4, 3, 0, 0, 0
    }
}