// 350. 两个数组的交集 II
// Created by kaide on 2021/4/3.
//
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 给定两个数组，计算它们的交集。
 * 《hash表》
 * @param nums1 数组1
 * @param nums2 数组2
 * @return  两个数组的交集
 */
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> mp;
    vector<int> ret;
    for (auto num:nums1) {
        mp[num]++;
    }
    for (auto num:nums2) {
        if (mp[num] > 0) {
            mp[num]--;
            ret.push_back(num);
        }
    }
    return ret;
}

int main(){
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> ret = intersect(nums1, nums2);
    for (auto r:ret) {
        printf("%d,", r);   // expect:[2,2]
    }
}