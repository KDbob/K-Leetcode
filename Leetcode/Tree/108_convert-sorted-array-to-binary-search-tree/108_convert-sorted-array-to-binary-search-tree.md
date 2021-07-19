#### [108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵 **高度平衡** 二叉搜索树。

**高度平衡** 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

```
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```
输入：nums = [1,3]
输出：[3,1]
解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。
```

# 解题思路

## 原理

- 查找二叉树的中序遍历一定是升序排列。
- 通过查找二叉树的中序遍历，不能唯一地确定二叉搜索树
- 增加限制条件（要求二叉树的高度平衡），也不能唯一地确定二叉搜索树。

#### 每次选择中间元素作为根节点，能够保证一定是平衡的

> 1382 题解中给出了这个方法的正确性证明：[1382 官方题解](https://leetcode-cn.com/problems/balance-a-binary-search-tree/solution/jiang-er-cha-sou-suo-shu-bian-ping-heng-by-leetcod/)

可以用递归的思想

- 确定了根节点后将数组一分为二：左右子树
- 左右子树分别也是平衡二叉树

### 算法流程

0. 确定根节点（中间靠左），将数组划分成左右子树
1. 递归确定左右子树的根节点
2. Base Case：递归到叶子节点

### 代码实现

初步代码实现

```c++
TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (!nums.empty()) {
        int root_index = nums.size() / 2;   // 偏右
        TreeNode *root = new TreeNode(nums[root_index]);
        vector<int> left(nums.begin(), nums.begin()+root_index);	// 这个写法会占用大量的内存，可以改成游标
        vector<int> right(nums.begin() + root_index +1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
    return nullptr;
}
```

拆分成递归子程序的写法：

```C++
TreeNode *structTree(vector<int> &nums, int left, int right) {
    if (left>right) {
        return nullptr;
    }
    int mid = (left + right + 1) / 2; // 总是选择中间位置靠右作为根节点
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = structTree(nums, left, mid - 1);
    root->right = structTree(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    return structTree(nums, 0, nums.size() - 1);
}
```



# 知识点总结

- C++中创建vector子数组的写法

  ```c++
  vector<int> right(nums.begin()-5, nums.end());
  ```

- 程序可以拆分成递归的子程序，用游标来代替变量。

- 其中选择中间位置的不同对构造而成的二叉树形态有影响

  ```c++
  int root_index = nums.size() / 2;   // 偏右
  int mid = (left + right) / 2;
  int mid = (left + right + rand() % 2) / 2;
  ```

  

