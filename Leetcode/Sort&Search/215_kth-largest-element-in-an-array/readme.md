#### [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

> #快速排序 #数组

给定整数数组 `nums` 和整数 `k`，请返回数组中第 `**k**` 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。

 

**示例 1:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

 

**提示：** 

- `1 <= k <= nums.length <= 104`
- `-104 <= nums[i] <= 104`



# 解题

## 方法一：基于快速排序的选择方法

### 1. 思路

借用快速排序中的partion算法思想

> partion可以使用快慢指针，算法复杂度O(n)

- 最后的排序的实际位置q，q前的数字都比它小，q后的数字都比它大
- 一次partition最后得到q的实际位置

**Partition的优化改进**

- 二分选择

  - 在分解过程中，对子数组进行划分，如果划分的q正好是需要的下标，就直接返回
  - 饭走，如果q比目标下标小，就递归右子区间。否则递归左子区间。

- 引入随机性

  > 如果每次规模为n的问题都划分成1和n-1,每次递归又向n-1的集合中递归，这种情况是最坏的。时间代价是O(n ²)，引入随机性后时间代价是O(n)

  - 做法是将基准元素重新排列一次


### 2 编程

#### 2.2 算法流程

#### 快速选择quickSelect

1. 执行partition，得到一个最终位置
2. 如果位置下标恰好是n-k（第k大是倒序）返回下标对应的值
3. 否则根据划分的区间，递归执行quickSelect算法

**partition算法的实现（快慢指针）**

1. 选最后一个元素作为基准元素x
2. 遍历数组
   - 如果指针i和j的值都小于x，交换i和j所指向的值，i和j同时前进一位
   - 否则只有j前进，i
3. i指向的值和基准元素交换

#### 2.3 代码实现

**快速选择quickSelect**

```c++
/**
 * 寻找到排序最终位于index的数
 * @return 下标
 */
int quickSelect(vector<int> &a, int l, int r, int index) {
    int q = randomPartition(a, l, r); // 优化点二
    if (q == index) {
        return a[q];
    } else {
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);   // 优化点一
    }
}
```

**partition算法**

```c++
/**
 * 划分算法（以a[r]作为基准）
 * @param a 数组
 * @param p 将要划分的起始位置
 * @param r 将要划分的结束位置
 * @return 这个数最终的index
 */
int partition(vector<int> &a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (a[j] < x) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;   // 这是第几大的数
}
```



### 3 复杂度分析

- 时间复杂度：O(n)
  - 已通过引入随机性优化到线性效果

- 空间复杂度：O(logn)
  - 使用栈空间的空间代价

# 总结

- C++中rand()返回，从0到最大随机数的任意整数