#### [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)

给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 `Solution` class:

- `Solution(int[] nums)` 使用整数数组 `nums` 初始化对象
- `int[] reset()` 重设数组到它的初始状态并返回
- `int[] shuffle()` 返回数组随机打乱后的结果

**示例：**

```
输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
```

##  方法一：暴力法（随机抽取）

##### 思路

假设把每个数都放在一个“帽子”中，然后从帽子中随机摸出数，摸出来的数按顺序地放入数组，那么这个数组正好就是要洗牌的数组

##### 数学证明

> 即要证明任何一个元素都会以等可能的概率被选中。

因为一个特定的元素e在第k轮被选中的概率为P(e在第k轮被选中)·P(e在前k轮不被选中)，这个概率公式如下：
$$
\frac{1}{n-k} \cdot \prod_{i=1}^{k} \frac{n-i}{n-i+1}
$$
将公式展开后：
$$
\left(\frac{n-1}{n} \cdot \frac{n-2}{n-1} \cdot(\ldots) \cdot \frac{n-k+1}{n-k+2} \cdot \frac{n-k}{n-k+1}\right) \cdot \frac{1}{n-k}
$$
k=0的情况下，满足1/n。k>0的情况下，也易知结果是1/n。因此这个数组的每个排列组合都是等概率的。

### 准备数据结构

`vector<int> array;`：用于输出值

`vector<int> original;`：用于保存原始数组

### 算法思路

准备一个临时的数组（深拷贝original）

`vector<int> aux(original);`

1. 遍历数组：
   1. 随机选取0～aux.size()-1的一个下标作为要移除索引：r
   2. 将array[i] = aux[r]，即将aux中抽到的数组按顺序赋给array
   3. 移除aux中r索引的值

2. 返回赋值完成后的array

### 代码实现

```C++
class Solution {
private:
    vector<int> array;
    vector<int> original;
    default_random_engine e;
public:
    Solution(vector<int> &nums) {
        array = nums;
        original = nums; 
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return array;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> aux(original);
        for (int i=0;i<original.size();i++){
            uniform_int_distribution<int> c(0, aux.size());
            int r = c(e);
            array[i] = aux[r];
            aux.erase(aux.begin() + r);
        }
        return array;
    }
};
```

### 复杂度分析

时间复杂度：$O(n^2)$

> aux.erase()这个函数的操作是线性时间的，总共发生n次。

空间复杂度：$O(n)$

> 重新实现重置方法，需要额外的空间把原始数组另存一份

## 方法二： Fisher-Yates 洗牌算法 （TODO）



# 知识点总结

- C++中指定范围的随机数

  ```c++
  default_random_engine e;
  uniform_int_distribution<int> c(0, 10);
  int r = c(e);		// 随机输出一个1~10之间的整数
  ```

  