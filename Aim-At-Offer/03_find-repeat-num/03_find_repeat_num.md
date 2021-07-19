# 数组中重复的数字

找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字

# 解题思路

1. 遍历数组，将出现过的数字都存入hash表
   - 在遍历的过程中判断这个数是否在hash表中出现过，出现过就返回该值。

### 准备数据结构：哈希表



# 知识点总结

```c++
int findRepeatNumber(vector<int> &nums) {
    unordered_map<int,int> mp;
    for(auto& num:nums) {
        mp[num]++;
        if(mp[num]>1)
            return num;
    }
    return -1;
}
```

1. C++的增强循环语法
2. 数据结构：unordered_map

