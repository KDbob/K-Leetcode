#### [46. 全排列](https://leetcode-cn.com/problems/permutations/)

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**示例 2：**

```
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

**示例 3：**

```
输入：nums = [1]
输出：[[1]]
```

 

**提示：**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数 **互不相同**



# 解题

## 方法一：回溯法

### 1. 思路

- 解空间可以视作一颗完全n叉树
  - 同[17. 电话号码的字母组合] 区别是但是选过的数字不能重复
  - 因此在重复的情况下剪枝，不继续遍历


### 2 编程

#### 2.1 数据结构

`vector<vector<int>> permutes;`：用于存储最后组合的结果

`vector<int> permite;`：临时存储，当一次完整深度的递归结束后，把值赋给permutes后就清空

`int index`（**递归关键变量**)：可以看作是递归的深度

#### 2.2 算法流程

1. 执行递归函数（深度从0开始）

   > 递归没有出口，遍历n叉树，但是在不满足的条件的子节点会剪枝（不会继续在该节点遍历下去）

   - 一个完整深度遍历的结束条件：index = nums.length时
        - 将临时容器permite的值加入到permutes中

   - （如果满足选数条件）遍历这个深度的数量，执行递归（index+1）
        - 保存到临时字符串数组中permutes

2. 返回permutes

#### 2.3 代码实现

1. 实现一个条件判断函数

```c++
bool pickCheck(vector<int> &picks,int num) {
    if (picks.size() == 0) return true;
    for (auto pick : picks) {
        if (pick == num) {
            return false;
        }
    }
    return true;
}
```

- 主函数以及调用

```C++
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> permutes;
    if (nums.size() == 0) return permutes;
    vector<int> permite;
    backtrace(nums, 0, permutes, permite);
    return permutes;
}

void backtrace(vector<int> &nums, int index, vector<vector<int>> &permutes, vector<int> &permite) {
    if (index == nums.size()) {
        permutes.push_back(permite);
    } else {
        for (auto num: nums) {
            if (pickCheck(permite,num)) {
                permite.push_back(num);
                backtrace(nums, index + 1, permutes, permite);
                permite.pop_back();
            }
        }
    }
}
```

# 总结

- 类似《4皇后问题》的回溯法思想，同[17. 电话号码的字母组合] 

- ★注意python中的值拷贝和引用拷贝

  - C++中这是值拷贝

    ```C++
    void backtrace(vector<int> &nums, int index, vector<vector<int>> &permutes, vector<int> &permite) {
        if (index == nums.size()) {
             permutes.push_back(permite);		// 值拷贝
            } else {
    ```

  - Python中的写法：

    ```python
    def backtrace(index: int):
        if index == len(nums):
            permutes.append(permute[:])  # 注：permutes.append(permute) 写法是错误的，相当于深拷贝。但是需求是只需要数组里的值，而不是引用
    ```

    

  ​	

  