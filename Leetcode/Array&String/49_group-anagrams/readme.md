#### [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

> #排序 #哈希表

给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。

**字母异位词** 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

 

**示例 1:**

```
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**示例 2:**

```
输入: strs = [""]
输出: [[""]]
```

**示例 3:**

```
输入: strs = ["a"]
输出: [["a"]]
```

 

# 解题

## 方法一：排序+哈希表

### 1. 思路

当两个字符串互为字母异位词时，当且仅当两个字符串包含的字母相同。

因此可以将**排序后的字符串**作为哈希表的**键值**。


### 2 编程

#### 2.1 数据结构

`unordered_map<string, vector<string>> mp;`:哈希表

`vector<vector<string>> ans;`:结果

#### 2.2 算法流程

1. 遍历每个字符串
   - 将该字符串排序成key，作为哈希表的键值
   - 将这个字符串的值放到对应键值下的列表中
2. 遍历哈希表，组成ans返回

#### 2.3 代码实现

```C++
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string &str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it=mp.begin(); it!=mp.end();it ++) {
        ans.emplace_back(it->second);
    }
    return ans;
}
```



### 3 复杂度分析

**时间复杂度**：*O*(n*klog*k)

> n是strs中字符串的数量，k是strs字符串中最大长度

- 其中排序*O*(*klog*k)

**空间复杂度**：*O*(nk)

# 总结

- C++中unorder_map的几种遍历方式

```c++
// 使用迭代器遍历
for (auto it=mp.begin(); it!=mp.end(); it ++) {
	ans.emplace_back(it->second);
}
```

- ★Python中的**哈希表实现思路**：tuple作为key

  > tuple不能重复，可以按字母顺序作为key，其中ord()函数返回unicode的值
  >
  > 使用 [`defaultdict`](https://docs.python.org/zh-cn/3/library/collections.html#collections.defaultdict) 例子，将（键-值对组成的）序列转换为（键-列表组成的）字典

  `defaultdict(<class 'list'>, {(1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0): ['eat']})`