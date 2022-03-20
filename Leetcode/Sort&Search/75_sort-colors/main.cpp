// 75. 颜色分类
// Created by bob on 2022/3/19.
//

#include <vector>
#include "KPrint.h"

using namespace std;

class Solution {
public:
void sortColors(vector<int> &nums) {
    int ptr = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            swap(nums[ptr], nums[i]);
            ptr++;
        }
    }
    for (int i = ptr; i < n; ++i) {
        if (nums[i] == 1) {
            swap(nums[ptr], nums[i]);
            ptr++;
        }
    }
}

    void sortColors2(vector<int> &nums) {
        int ptr0 = 0, ptr1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[ptr1], nums[i]);
                ptr1++;
            }
            if (nums[i] == 0) {
                swap(nums[ptr0], nums[i]);
                if (ptr0 < ptr1) {
                    swap(nums[ptr1], nums[i]);
                }
                ptr0++;
                ptr1++;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution().sortColors2(nums);
    printVector(nums);  // expect: {0,0,1,1,2,2}
}