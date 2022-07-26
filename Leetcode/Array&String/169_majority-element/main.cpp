// 169. 多数元素
// Created by bob on 2022/7/26.
//

#include<vector>
#include<unordered_map>

using namespace std;

/**
 * 方法二：分治
 */
class Solution {
private:
    int countInRange(vector<int>& nums, int target, int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (nums[i] == target)
                count++;
        }
        return count;
    }
    
    int majorityElementRec(vector<int>& nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        int mid = (low + high) / 2;
        int left_majority = majorityElementRec(nums, low, mid);
        int right_majority = majorityElementRec(nums, mid + 1, high);
        if (countInRange(nums, left_majority, low, high) > (high - low + 1) / 2) {
            return left_majority;
        }
        if (countInRange(nums, right_majority, low, high) > (high - low + 1) / 2) {
            return right_majority;
        }
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};

/**
 * 方法一：hash表
 */
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            counts[num]++;
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};


int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = Solution().majorityElement(nums);
    int res2 = Solution2().majorityElement(nums);
    printf("%d", res2);
    return 0;
}