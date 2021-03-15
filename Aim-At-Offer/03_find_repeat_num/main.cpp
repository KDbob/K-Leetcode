//
// Created by kaide on 2021/3/14.
//
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Topic 03: 找到数组中重复出现的数字
 * 《使用hash表的思想》
 * @param nums 数组
 * @return 重复出现的数字
 */
int findRepeatNumber(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (auto &num:nums) {
        mp[num]++;
        if (mp[num] > 1)
            return num;
    }
    return -1;
}


int main() {
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int find = findRepeatNumber(nums);
    printf("repeat num is %d", find);   // expect: 2
    return 0;
}