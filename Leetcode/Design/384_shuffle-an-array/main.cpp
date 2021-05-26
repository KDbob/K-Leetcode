// 384. 打乱数组
// Created by kaide on 2021/5/26.
//
#include <vector>
#include <random>

using namespace std;

/**
 * 法来打乱一个没有重复元素的数组
 * 《暴力法》
 */
class Solution {
private:
    vector<int> array;
    vector<int> original;
    default_random_engine e;
public:
    Solution(vector<int> &nums) {
        array = nums;
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return array;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> aux(original);
        for (int i=0;i<original.size();i++){
            uniform_int_distribution<int> c(0, aux.size());
            int r = c(e);
            array[i] = aux[r];
            aux.erase(aux.begin() + r);
        }
        return array;
    }
};

/*
 * 打印数组
 */
void printArray(const vector<int>& arr) {
    for (auto n:arr) {
        printf("%d ", n);
    }
    printf("\n");
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s = Solution(nums);
    printArray(s.shuffle());
    printArray(s.reset());
    printArray(s.shuffle());

}