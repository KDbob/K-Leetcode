#### [103. 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

> #二叉树 #层次遍历 #BFS

给你二叉树的根节点 `root` ，返回其节点值的 **锯齿形层序遍历** 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

## 方法一：BFS遍历+条件

### 1. 思路

利用102题的思想，只是改变每层进队列的顺序（**只需要改变结果队列**，使用双端队列）

- 偶数层从左往右进入队列
- 奇数层从右往左进入队列


### 2 编程

#### 2.1 数据结构

`Queue <vector<tree *>> q`：用于存储遍历过的节点

> 以[tree *]的形式保存在queue中，一个数组表示一层

`vector<vector<int>> res`：用于存储BFS遍历输出的值

`deque<int> leveList`:**每一层的结果队列**：根据奇偶层，分从头插入和从尾插入

#### 2.2 算法流程

0. 将根节点压入队列中

1. 对二叉树进行深度遍历（BFS）（大循环条件：队列中还有节点）

   1. 从队头取出一层的元素，遍历这层的元素

      1. 将这层取出的值存储到res数组中以便数组
         - **如果是奇数层，从队头插入数组**
         - 如果是偶数层，从队尾插入数组

      - 如果这层的元素有子节点（left和right），将[left1, right2, ....]加入到队尾

2. 遍历结束，返回res数组。

#### 2.3 代码实现

```c++
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool isOrderLeft = true;    // 偶数层，结果队列是从左至右

    while (!q.empty()) {
        deque<int> leveList;
        int currentLayerNum = q.size();
        for (int i = 0; i < currentLayerNum; ++i) {
            auto node = q.front();
            q.pop();
            if (isOrderLeft) {
                leveList.push_back(node->val);
            } else {
                leveList.push_front(node->val);
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.push_back(vector<int>{leveList.begin(), leveList.end()});
        isOrderLeft = !isOrderLeft;
    }
    return res;
}
```

### 

# 总结

- C++中的双端队列`deque`:

  ```c++
  deque<int> leveList;
  leveList.push_back(node->val);	// 从队尾插入
  leveList.push_front(node->val);	// 从队头插入
  vector<int> tempList = vector<int>{leveList.begin(), leveList.end()} // 转换成vector
  ```

  

