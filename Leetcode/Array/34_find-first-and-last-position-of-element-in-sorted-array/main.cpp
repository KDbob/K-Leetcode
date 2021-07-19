// 34. 在排序数组中查找元素的第一个和最后一个位置
// Created by bob on 2021/7/19.
//
#include "vector"

using namespace std;

int findFirstIndx(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
            // 下轮继续寻找[mid+1, high]
            low = mid + 1;
        } else if (nums[mid] == target) {
            // 下轮继续寻找[left ,mid]
            high = mid;
        } else {
            // 下轮继续寻找[left, mid-1]
            high = mid - 1;
        }
    }
    if (nums[low] == target) return low;
    return -1;
}

int findLastIndx(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (nums[mid] < target) {
            // 下轮继续寻找[mid+1, high]
            low = mid + 1;
        } else if (nums[mid] == target) {
            // 下轮继续寻找[mid, right]
            low = mid;
        } else {
            // 下轮继续寻找[left, mid-1]
            high = mid - 1;
        }
    }
    return low;
}

/**
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * @param nums 按照升序排列的整数数组
 * @param target 目标值
 * @return 目标值在数组中的开始位置和结束位置
 */
vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return vector<int>{-1, -1};
    }

    int first = findFirstIndx(nums, target);
    if (first == -1) {
        return vector<int>{-1, -1};
    }
    int last = findLastIndx(nums, target);
    return vector<int>{first, last};
}

void printVector(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        printf("%d", nums[i]);
        if (i != nums.size() - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(nums, 8);
    printVector(res);
}