#### [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

给你一个二叉树，请你返回其按 **层序遍历** 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

**示例：**
二叉树：`[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层序遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]
```

# 解题思路

## 方法一：使用广度遍历（BFS）

> 借助队列这样的数据结构，实现广度遍历

### 准备数据结构

`Queue <vector<tree *>> q`：用于存储遍历过的节点

> 以[tree *]的形式保存在queue中，一个数组表示一层

`vector<vector<int>> res`：用于存储BFS遍历输出的值

### 算法流程（遍历流程）

0. 将根节点压入队列中

1. 对二叉树进行深度遍历（BFS）（大循环条件：队列中还有节点）

   1. 从队头取出一层的元素，遍历这层的元素

      1. 将这层取出的值存储到res数组中以便数组

      - 如果这层的元素有子节点（left和right），将[left1, right2, ....]加入到队尾

2. 遍历结束，返回res数组。

#### 代码实现

- 初版的代码实现：

```c++
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<vector<TreeNode *>> q;
    q.push({root});
    while (!q.empty()) {
        vector<TreeNode *> curr_layer = q.front();
        q.pop();
        vector<int> vals;
        vector<TreeNode *> next_layer;
        for (auto &n:curr_layer) {
            vals.push_back(n->val);
            if (n->left) next_layer.push_back(n->left);
            if (n->right) next_layer.push_back(n->right);
        }
        res.push_back(vals);
        if (next_layer.size() > 0) {
            q.push(next_layer);
        }
    }
    return res;
}
```

#### 由于每次循环开始时，队列中的元素个数一定是当前层的元素个数。因此可以优化代码：

`Queue <vector<tree *>> q`改成 `Queue <tree *> q`即可。

> ★这个改动，可以省去两个变量：curr_layer和next_layer

- 不需要用数组来区分是哪一层
- 仅用一个变量：currentLayerNum来取当前层的节点。

于是修改后的代码如下：





# 知识点总结

- 代码重构：节省一个临时vector变量：

  ```c++
  // 原代码：每次循环都创建一个临时变量
  vector <vector <int>> ret;
  循环体：
    vector<int> vals;
  	循环体:
  		vals.push_back(n->val);
  	res.push_back(vals);
  
  // 重构代码：使用vector.back()
  vector <vector <int>> ret;
  循环体：
    res.push_back(vector<int>());	// 先占坑
  	循环体：
  	res.back().push_back(n->val);	// 再用back定位到尾部的坑
  ```



