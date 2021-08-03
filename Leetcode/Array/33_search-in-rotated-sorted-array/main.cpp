// 33. 搜索旋转排序数组
// Created by bob on 2021/8/3.
//
#include "vector"

using namespace std;

/**
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 《二分查找法》
 * @param nums 旋转后的数组nums
 * @param target 整数target
 * @return -1或者目标值的下标
 */
int search(vector<int> &nums, int target) {
    int n = nums.size();
    if (!n) return -1;
    if (n == 1) return nums[0] == target ? 0 : -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if (nums[mid] <= nums[l]) {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = search(nums, 0);  // expect: 4
    printf("%d\n", res);

    vector<int> nums2 = {1};
    int res2 = search(nums2, 0);  // expect: -1
    printf("%d\n", res2);
}