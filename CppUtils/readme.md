# Leetcode工具类

## 1. 链表工具

#### 1.1 链表节点数据结构

```c++
typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

}ListNode;
```



## 2. 树节点

### 2.1 树节点数据结构

```c++
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
} TreeNode;
```

### 2.2 树的构造方法

1. 前序+中序构造二叉树（普通二叉树）

   `TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);`

2. 层序构造完全二叉树

   `TreeNode *buildTree(vector<int> &levelorder);`