#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 

# 解题思路

## 方法一：DFS深度遍历（栈版本）

> 可以用一个栈作为辅助数据结构，同时记录栈的最大高度，经过一次完整的遍历后统计栈的最大高度。

#### 准备数据结构

`set <*Tree> set;`

> 用于DFS判断是否见过

`stack<*Tree> stk；`

> 用于DFS遍历

`int maxLayers = 0;`

> 用于记录栈的最大高度。

#### 算法流程

1. 对二叉树进行深度遍历（DFS）（大循环条件：栈中还有节点）

   0. 将根节点压入栈中
   1. 判断该节点的子节点是否为空（如果不为空）
      - 如果为空（左子树为空），弹出栈顶，继续转1
      - 如果不为空：是否seen过
        - 左子树没有seen过，将左节点压入栈中，继续执行1操作（此时更新栈的最高高度）
        - 左子树seen过，右子树没有seen过，将右节点压入栈中，继续执行1操作（此时更新栈最高高度）
        - 左右都seen过，弹出栈顶，继续转1

   2. 遍历结束，返回栈的最高高度

#### 代码实现

```C++
int maxDepth_stack(TreeNode* root) {
    stack<TreeNode *> stk;
    unordered_set<TreeNode *> seen;
    int maxDepth = 0;
    if (root) {
        stk.push(root);
        maxDepth++;
    }
    while (!stk.empty()) {
        TreeNode *top = stk.top();
        if (!top->left && !top->right) {
            stk.pop();
        } else if (top->left && !seen.count(top->left)) {
            stk.push(top->left);
            seen.insert(top->left);
            if (stk.size()> maxDepth) maxDepth = stk.size();
        } else if (top->right && !seen.count(top->right)) {
            stk.push(top->right);
            seen.insert(top->right);
            if (stk.size()> maxDepth) maxDepth = stk.size();
        } else {
            stk.pop();
        }
    }
    return maxDepth;
}

```



#### 复杂度分析

时间复杂度：$O(n)$

空间复杂度：$O(n)$

## 方法二：DFS深度遍历（递归版本）

> 判断最大深度存在递归表达式

$$
maxDepth = MaxDepth(LeftTree, rightTree) + 1;
$$

因此可以直接写出递归表达时的代码

#### 递归实现代码：

> 注：递归的base case是空节点。此时的深度应为0

```C++
int maxDepth(TreeNode* root) {
    if (root) {
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return (leftMax > rightMax) ? leftMax + 1 : rightMax + 1;
    } else {
        return 0;
    }
}
```





