// 剑指 Offer 11. 旋转数组的最小数字
// Created by kaide on 2021/4/9.
//
#include <vector>

using namespace std;

/**
 * 查找旋转数组中的最小值
 *《利用二分查找确定最后的坐标》
 * @param numbers 旋转数组
 * @return 旋转数组中的最小值
 */
int minArray(vector<int>& numbers) {
    int low = 0, high = numbers.size()-1;
    int mid;
    while (low < high) {
        mid = (high + low) / 2;
        if (numbers[mid] > numbers[high]) {
            low = mid + 1;
        } else if (numbers[mid] < numbers[high]) {
            high = mid;
        } else {
            high-=1;
        }
    }
    return numbers[high];
}

int main(){
    vector<int> nums = {2,2,2,0,1};
    int min = minArray(nums);
    printf("%d\n", min);
}