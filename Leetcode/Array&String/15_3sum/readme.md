#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

> #数组 #循环优化 #双指针 #证明

给你一个包含 `n` 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？请你找出所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

 

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

**示例 2：**

```
输入：nums = []
输出：[]
```

**示例 3：**

```
输入：nums = [0]
输出：[]
```

 

# 解题

## 方法一：排序+双指针

### 1. 思路

最简单的想法是三重循环枚举三元组，时间复杂度：$O(N^3)$。优化改进可以达到$O(N^2)$的复杂度

#### 优化点

> 因为题目有约束条件，不重复：那么枚举的三元组(a, b, c)一定满足a ≤b ≤c。在这个前提下：

- 先排序
  - 这样a、b、c可以按顺序枚举
  - 对于每重循环，相邻两次枚举的元素不能相同，否者会造成重复。

- 双指针：

  > 在固定了a的时候，b和c视作两个指针

  - b按顺序遍历（向→遍历）
  - c按逆序遍历（向←遍历）

  **为什么可以这么做（证明）：**

  - 因为如果固定了a和b，那么存在唯一的c满足：a+b+c=0
  - 当b往后枚举一个元素b'时，由于b'>b，那么满足a+b'+c'=0的c‘一定有c'<c。也就是说我们可以从小到大枚举b，同时从大到小枚举c，**即第二重循环和第三重循环实际上是并列的关系**（二三重循环的时间复杂度加起来为$O(N)$）


### 2 编程

#### 2.1 数据结构

`vector<vector<int>> ans`：返回运算的结果

#### 2.2 算法流程

1. 先对数组进行排序
2. 对数组进行遍历：
   - 第一层循环，枚举a。（下一个a不能和前一个a相同）
   - 第二层循环，b从first+1开始，同时c按逆序遍历
     - 如果找到满足条件的a+b+c=0，存入ans
3. 遍历结束返回ans

#### 2.3 代码实现

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 先进行排序
    vector<vector<int>> ans;
    for (int first = 0; first < n; first++) {
        if (first >0 && nums[first] == nums[first-1]) {
            continue;
        }
        int third = n - 1;
        int target = -nums[first];
        for (int second = first + 1; second < n; ++second) {
            if (second > first + 1 && nums[second] == nums[second-1]) {     // 需要和上一次枚举的数不相同
                continue;
            }
            while (second < third && nums[second] + nums[third] > target) { // 不等式的一个变形
                third--;
            }
            if (second == third) {  // b=c时，不能满足不重复条件，提前结束循环
                break;
            }
            if (nums[first] + nums[second] + nums[third] == 0) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}
```

### 3 复杂度分析

- 时间复杂度：$O(N^2)$
  - 其中排序复杂度$O(logN)$+遍历$O(N^2)$
- 空间复杂度：$O(logN)$
  - 额外的排序的空间复杂度为$O(logN)$




# 总结

- 双指针适用：当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法