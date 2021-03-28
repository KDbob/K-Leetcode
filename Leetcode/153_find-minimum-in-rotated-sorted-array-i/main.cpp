//
// Created by kaide on 2021/3/27.
//
#include <vector>

using namespace std;

/**
 * 查找旋转数组中的最小值
 * 《二分查找思想》
 * @param nums 旋转数组
 * @return 最小值
 */
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    if (nums[0] <= nums[right]) return nums[0];     // 如果是非旋转序列
    while (left < right) {
        int mid = (right + left) /2;
        if (mid >= 1 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[0] < nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    int i1 = findMin(v1);
    printf("%d\n", i1);
    vector<int> v2 = {11, 13, 15, 17};
    int i2 = findMin(v2);
    printf("%d\n", i2);
    vector<int> v3 = {2,3,4,5,1};
    int i3 = findMin(v3);
    printf("%d\n", i3);
    vector<int> v4 = {1};
    int i4 = findMin(v4);
    printf("%d\n", i4);
}