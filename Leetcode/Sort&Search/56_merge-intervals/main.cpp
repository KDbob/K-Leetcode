// 56. 合并区间
// Created by bob on 2022/4/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
     * 合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
     * @param intervals 若干个区间的集合
     * @return 合并区间后的集合
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i=1; i < intervals.size(); i++) {
            int m_R = merged.back()[1];     // merged中最后一个区间的右闭值
            int L = intervals[i][0], R = intervals[i][1];
            if (L > m_R) {
                merged.push_back(intervals[i]);
            } else {
                merged.back()[1] = max(m_R, R);
            }
        }
        return merged;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,  3}, {2,  6}, {8,  10}, {15, 18}};
    vector<vector<int>> res = Solution().merge(intervals);
    return 0;
}