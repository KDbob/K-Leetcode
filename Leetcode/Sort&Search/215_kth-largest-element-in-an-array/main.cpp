// 215. 数组中的第K个最大元素
// Created by bob on 2022/3/23.
//
#include<vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

/**
 * 寻找到排序最终位于index的数
 * @return 下标
 */
int quickSelect(vector<int> &a, int l, int r, int index) {
    int q = randomPartition(a, l, r); // 优化点二
    if (q == index) {
        return a[q];
    } else {
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);   // 优化点一
    }
}

    int randomPartition(vector<int> &a, int l, int r) {
        int i = rand() % (r - l + 1) + 1;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    /**
     * 划分算法（以a[r]作为基准）
     * @param a 数组
     * @param p 将要划分的起始位置
     * @param r 将要划分的结束位置
     * @return 这个数最终的index
     */
    int partition(vector<int> &a, int p, int r) {
        int x = a[r];
        int i = p - 1;
        for (int j = p; j < r; ++j) {
            if (a[j] < x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;   // 这是第几大的数
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int result = Solution().findKthLargest(nums, 2);
    printf("%d", result);   // expect: 5
}