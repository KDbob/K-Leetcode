# [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

#递归构造 #二叉树 #树的遍历

给定一棵树的前序遍历 `preorder` 与中序遍历 `inorder`。请构造二叉树并返回其根节点。

 

**示例 1:**

![img](105_construct-binary-tree-from-preorder-and-inorder-traversal.assets/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**示例 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

 

**提示:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` 和 `inorder` 均无重复元素
- `inorder` 均出现在 `preorder`
- `preorder` 保证为二叉树的前序遍历序列
- `inorder` 保证为二叉树的中序遍历序列

通过次数288,234

提交次数407,457



# 解题

## 方法一：递归构造

### 1. 思路

![image-20220207084252916](105_construct-binary-tree-from-preorder-and-inorder-traversal.assets/image-20220207084252916.png)

### 2 编程

#### 2.1 算法流程

##### 主算法：调用子算法

1. 调用递归子算法，传入初始值

##### 子算法：递归构建二叉树

> 递归的结束条件是左右子树都为零

1. 通过[前序]确定二叉树的**顶点**，记下标为：preorder_index

   - 构建树节点：TreeNode(preorder_val)

2. 通过该顶点在[中序]的位置，分别构建左右子树

   > 通过preorder_val在[中序]中的位置，定位左右子树顶点的下一个顶点：preorder_index

   - 左子树顶点位置`= preorder_index + 1`

   - ★右子树顶点位置`= preorder_index + 1 + rightLength  `

     > 其中 rightLength 是这个顶点的左子树节点个数 

3. 左右子树递归执行第1和2两步

#### 2.1 数据结构

> 构建二叉树的子算法所需要的数据结构

`int preorder_index = 0；`：顶点在[前序]中的位置

` int inorder_leftIndex, inorder_rightIndex `：用于记录[中序]子序列的起始和结束位置

`unordered_map<int,int> map`：[前序]值在中序中的位置

>  为了快速定位preorder_index在中序遍历中的位置，可以事先用一个map保存映射关系，当然也可通过计算出来

#### 2.3 代码实现

```c++
/**
 *
 * @param preorder 中序遍历数组
 * @param preorderIndex 前序的节点的索引
 * @param inorderLeftIndex 中序的起始位置（递归构造哪部分子树）
 * @param inorderRightIndex 中序的结束位置
 * @return 构造好的二叉树
 */
TreeNode *myTree(vector<int> &preorder, int preorderIndex, int inorderLeftIndex, int inorderRightIndex) {
    int inorderRootIndex = map[preorder[preorderIndex]];
    int leftLength = inorderRootIndex - inorderLeftIndex;
    int rightLength = inorderRightIndex - inorderRootIndex;
    TreeNode *root = new TreeNode(preorder[preorderIndex]);
    if (leftLength > 0) {
        root->left = myTree(preorder, preorderIndex + 1, inorderLeftIndex, inorderRootIndex - 1);
    }
    if (rightLength > 0) {
        root->right = myTree(preorder, preorderIndex + 1 + leftLength, inorderRootIndex + 1,
                             inorderRootIndex);
    }
    return root;
}
```

### 3 复杂度分析

- 时间复杂度：$O(n)$，n是树中的节点个数。

- 空间复杂度：$O(n)$

  - 树的存储空间$O(n)$

  - 存储hash映射的空间$O(n)$
  - 递归时栈空间$O(h)$，其中$h<n$



# 总结

- 递归构造和迭代构造一般可同时解决这种问题
- 递归设置的变量一般需要前和后两个下标
- 使用hashmap存储映射关系



