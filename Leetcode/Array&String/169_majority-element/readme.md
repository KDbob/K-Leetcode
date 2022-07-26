#### [169. 多数元素](https://leetcode.cn/problems/majority-element/)

难度简单1509收藏分享切换为英文接收动态反馈

给定一个大小为 `n` 的数组 `nums` ，返回其中的多数元素。多数元素是指在数组中出现次数 **大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

**示例 1：**

```
输入：nums = [3,2,3]
输出：3
```

**示例 2：**

```
输入：nums = [2,2,1,1,1,2,2]
输出：2
```

# 方法一：hash表



# 方法二：分治

### 1. 算法思路

如果数 `a` 是数组 `nums` 的众数，如果我们将 `nums` 分成两部分，那么 `a` 必定是至少一部分的众数。





# 总结

1. python中的sum函数计数语法

```python
        def count_in_range(target, low, high):
            count = 0
            for i in range(low, high + 1):
                if nums[i] == target:
                    count += 1
            return count
        #等价于：
        def count_in_range(target, low, high):
            return sum(1 for i in range(low, high + 1) if i == target)
```

