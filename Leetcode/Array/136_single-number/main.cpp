// 136. 只出现一次的数字
// Created by kaide on 2021/4/2.
//
#include <vector>

using namespace std;

/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 《⊕运算》
 * @param nums
 * @return
 */
int singleNumber(vector<int> &nums) {
    int a = 0;
    for (auto num:nums) {
        a ^= num;
    }
    return a;
}

int main() {
    vector<int> nums{4, 1, 2, 1, 2};
    int i = singleNumber(nums);   // expect:4
    printf("%d", i);
}