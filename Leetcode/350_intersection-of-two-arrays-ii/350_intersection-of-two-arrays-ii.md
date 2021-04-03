#### [350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)

给定两个数组，编写一个函数来计算它们的交集。

示例 1：

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
```


示例 2:

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
```


说明：

- 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
- 我们可以不考虑输出结果的顺序。

进阶：

- 如果给定的数组已经排好序呢？你将如何优化你的算法？
- 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
- 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

# 解题思路

## 方法一：hash表

可以首先将nums1遍历一次存储到hash表中，每个数字出现一次即++一次，这样可以得到一个统计了每个数字**出现次数**的hash表

然后遍历nums2一次，对每个在hash表中**出现次数**--一次，并且保存在交集数组中输出。

#### 准备数据结构：

hash表：用于统计nums1中每个数字出现的频率。

数组ret：用于存储交集数组。

#### 算法流程：

0. 如果nums2数组长度更短，将nums2作为nums1。（节省存储空间）

1. 遍历nums1数组，将数字出现频率存储在hash表中
2. 遍历nums2数组，在hash表中查找是否有相应的数字：
   - 如果有记录相应的数字的**出现次数**，将结果放到ret中，并且**出现次数--**
   - 没有相应的数字，继续遍历
3. 返回ret数组

```c++
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
```



#### 复杂度分析

m和n分别代表nums1的数组长度和nums2的数组长度。

时间复杂度：$O(m+n)$

> 两次遍历的for循环

空间复杂度：$O(min(m,n))$

> 对较短的数组进行哈希表的操作，哈希表的大小不会超过较短的数组的长度

# 知识点总结

- hash表法首先需要判断两个数组谁更长，因为如果将较短的数组存储为hash表，hash表的存储空间得到了节省。

