// 347. 前 K 个高频元素
// Created by bob on 2022/5/7.
//
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto &v: nums) {
            occurrences[v]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto &[nums, count] : occurrences) {
            if (q.size() < k) {     // 直接建立小根堆
                q.emplace(nums, count);
            } else {
                if (q.top().second < count) {   // 重新调整小根堆
                    q.pop();
                    q.emplace(nums, count);
                }
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int>res = Solution().topKFrequent(nums, k);  // expect: [1, 2]
    return 0;
}