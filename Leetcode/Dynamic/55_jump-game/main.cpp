// 55.跳跃游戏
// Created by bob on 2022/4/5.
//
#include<vector>

using namespace std;

class Solution {
public:

    /**
     * 数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个下标。
     * 《达到的最远位置：从前往后推》
     * @param nums 非负整数数组
     * @return 是否能够到达最后一个下标
     */
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach) return false;    // 说明这一步不能通过前者达到，那么后面更达不到了
            reach = max(i + nums[i], reach);
        }
        return true;
    }
    /**
     * 方法二：从后往前推
     */
    bool canJump2(vector<int> &nums) {
        int n = nums.size();
        int last = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if ((nums[i] + i) >= last) {
                last = i;
            }
        }
        return last == 0;
    }

};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    bool res = Solution().canJump2(nums);
    if (res) {
        printf("可以到达");
    } else {
        printf("不能到达");
    }
}