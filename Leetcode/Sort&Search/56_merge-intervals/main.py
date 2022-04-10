from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = list()
        n = len(intervals)
        merged.append(intervals[0])
        for i in range(1, n):
            m_R = merged[-1][1]     # merged中最后一个区间的右闭值
            L, R = intervals[i][0], intervals[i][1],
            if L > m_R:
                merged.append(intervals[i])
            else:
                merged[-1][1] = max(m_R, R)
        return merged


if __name__ == '__main__':
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    res = Solution().merge(intervals)
    print(res)  # expect: [[1,6], [8,10], [15,18]
