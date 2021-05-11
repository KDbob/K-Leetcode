#### [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    		1
       / \
      2   2
     / \ / \
    3  4 4  3



但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

```
		1
   / \
  2   2
   \   \
   3    3
```

# 解题思路

## 方法一：递归法（双指针左右判断）

> 观察对称的二叉树具有如下性质：
>
> - 根节点出发的左右两个节点的值相等：root->left->val == root->right->val
> - 假设从根节点出发的两个节点是镜像节点（上图的2为例），假设分别是L和R，则有：
>   - L->val == R->val
>   - L->left->val == R->right->val
>   - L->right->val == R->left->val

### 算法流程

##### 那么可以设计一个验证L子树和R子树是否为对称的函数：`valid(lNode, rNode)`

0. 递归函数base case，当lNode和rNode同时为空，返回true
   - 当lNode和rNode中有一个为空，一个不为空，返回false
1. 验证lNode，rNode是否是镜像节点
   - lNode->val和rNode->val不想等，返回false
   - 验证lNode->left和rNode->right是否是镜像节点，同时lNode->right和rNode->left是否是镜像节点（递归）

##### 程序入口

`valid(root->left, root->right)`

### 代码实现

```C++
bool valid(TreeNode *lNode, TreeNode *rNode) {
    if (lNode == nullptr && rNode == nullptr) return true;
    if (lNode == nullptr || rNode == nullptr) return false;
    if (lNode->val != rNode->val) return false;
    return valid(lNode->left, rNode->right) && valid(lNode->right, rNode->left);
}

bool isSymmetric(TreeNode* root) {
    return valid(root->left, root->right);
}
```

