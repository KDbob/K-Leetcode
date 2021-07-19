// 154. 寻找旋转排序数组中的最小值 II
// Created by kaide on 2021/3/28.
//

#include <vector>

using namespace std;
/**
 * 查找旋转数组中的最小值
 * 《二分查找循环体中做判断》
 * @param nums 旋转数组
 * @return 最小值
 */
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    if (right == 0 || nums[0] < nums[right]) return nums[0];     // 如果是非旋转序列[1] [1,2,3] [1,1]
    int mid;
    while (left <= right) {
        mid = left + (right - left) /2;
        if (mid >= 1 && nums[mid] < nums[mid - 1]) {    // 防止出现mums[-1]
            return nums[mid];
        }
        if (mid <nums.size()-1 && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        if (nums[mid] < nums [right]) {
            right = mid - 1;
        } else if (nums[mid] > nums[right]){
            left = mid + 1;
        } else {
            right -=1;
        }
    }
    return nums[mid];
}


/**
 * 查找旋转数组中的最小值
 * 《利用二分查找确定最后的坐标》
 * @param nums
 * @return
 */
int findMin1(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {
            high = pivot;
        }
        else if (nums[pivot] > nums[high]) {
            low = pivot + 1;
        }
        else {
            high -= 1;
        }
    }
    return nums[low];
}

int main() {
//    vector<int> v1 = {1, 1};
//    int i1 = findMin(v1);
//    printf("%d\n", i1);
    vector<int> v2 = {10,1,10,10,10};
    int i2 = findMin(v2);
    printf("%d\n", i2);
//    vector<int> v3 = {3,3,3,1,1,3,3};
//    int i3 = findMin(v3);
//    printf("%d\n", i3);
    vector<int> v4 = {3,1,3};
    int i4 = findMin(v4);
    printf("%d\n", i4);
}