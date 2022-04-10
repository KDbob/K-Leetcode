#### [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)

> #排序 #合并

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]`。请你合并所有重叠的区间，并返回 *一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间* 。

 

**示例 1：**

```
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2：**

```
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

 

# 解题

## 方法：排序并合并

1. 先按区间的左端排序

2. 准备一个数组merged对所有区间进行遍历，**对当前区间进行判断**★：

   - 如果当前区间的左端点在数组merged最右一个区间的右端点之后，直接加入到merged的末尾

     > 因为他们不会重合，例如：merged=[[1,6]]，当前是[8,10]，应该直接加入[[1,6], [8,10]]

   - 否则，需要判断两者中右端点较大的值，更新merged中的区间

     > merged=[1,3]，当前是[2,6]，应该合并成merged=[1,6]

**需证明该方法的正确性**

> 反证法：在排完序后的数组中，两个本应合并的区间没能被合并。
>
> 需证明结论：所有能够合并的区间都必然是连续的

#### 代码实现

```c++
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
```

