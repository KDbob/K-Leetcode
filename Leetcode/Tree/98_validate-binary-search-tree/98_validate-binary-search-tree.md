#### [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

```
输入:
    2
   / \
  1   3
输出: true
```

示例 2:

```
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
```

# 解题思路

## 方法一：递归（利用性质）

可以根据二叉搜索树具有的性质：

- 节点的**左子树中所有节点的值**均小于节点的值
- 节点的**右子树中所有节点的值**均大于节点的值

### 算法流程

##### 那么可以设计一个验证搜索树递归函数：`valid(node, lower, upper)`

>  从二叉树的根节点开始执行验证，初始状态`valid(root, -inf, inf)`，其中-inf, inf分别表示为无穷小和无穷大（同时表示根节点是默认是一颗搜索树）

0. 递归的base case：如果node是空，返回true

1. 验证当前的节点是否满足范围

   > ★仅在条件不满足的情况下返回false

2. 验证左右子树：
   1. 验证左子树是否是二叉搜索树：`valid(root.left, -inf, node.val)`

      > 因为左子树中的所有值需要在(-inf, node.val)这个范围中（开区间）

   2. 验证右子树是否是二叉搜索树：`valid(root.right, node.val, inf)`

      > 因为右子树中的所有值需要在(node.val, inf)这个范围中（开区间）

   3. 递归式返回true。左右子树验证有效，是搜索树。有一边不满足，返回flase

### 代码实现

```C++
bool valid(TreeNode *node, int lower, int upper) {
    if (node == nullptr) {
        return true;
    }
    if (node->val <=lower || node->val >= upper) {
        return false;
    }
    return valid(node->left, lower, node->val) && valid(node->right, node->val, upper);
}
```

# 知识点总结

- 错误的递归思路

  - 这个递归是自底向上，需要用到底部的值来得到上个节点的值。（递归作用之一）
  - 但在这个问题上，递归不需要用底部的信息。而是通过前序遍历的方式逐一判断

  ```C++
  bool valid(TreeNode *node, int lower, int upper) {
      if (node->left && node->right) {
          bool left_valid = valid(node->left, lower, node->val);
          bool right_valid = valid(node->right, node->val, upper);
          if (left_valid && right_valid) {
              return true;
          } else {
              return false;
          }
      } else {
          if (lower < node->val && node->val < upper) {
              return true;
          } else {
              return false;
          }
      }
  }
  ```

- 逻辑式的简写

  ```C++
  bool left_valid = valid(node->left, lower, node->val);
  bool right_valid = valid(node->right, node->val, upper);
  if (left_valid && right_valid) {
     return true;
  } else {
     return false;
  }
  ```

  

​	

