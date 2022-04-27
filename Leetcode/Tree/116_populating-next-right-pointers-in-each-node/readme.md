#### [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

> #二叉树 #层序遍历 #BFS #构建 #链表

给定一个 **完美二叉树** ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL`。

初始状态下，所有 next 指针都被设置为 `NULL`。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
```



**示例 2:**

```
输入：root = []
输出：[]
```



## 方法一：层序遍历

### 1. 思路

借助[102题层序遍历的思想](/K-Leetcode/Leetcode/Tree/102_binary-tree-level-order-traversal)在每层遍历节点的时候，加入连接操作

## 2 算法流程

> 黑体部分表示区别的地方

0. 将根节点压入队列中

1. 对二叉树进行深度遍历（BFS）（大循环条件：队列中还有节点）

   1. 从队头取出一层的元素，遍历这层的元素

      - **如果这个节点有下一个兄弟节点（进行连接操作）**

      - 如果这层的元素有子节点（left和right），将[left1, right2, ....]加入到队尾

2. 遍历结束，返回res数组。

## 3 代码实现

```c++
/**
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * @param root 完美二叉树
 * @return  连接后的完美二叉树
 */
Node* connect(Node* root) {
    if (root == nullptr) {
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLayerNum = q.size();
        for (int i = 0; i < currentLayerNum; ++i) {
            Node *n = q.front();
            // 连接
            q.pop();
            if (i < currentLayerNum -1) {
                n->next = q.front();
            }
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
    }
    return root;
}
```



# 总结

- python中的双端队列：

  ```python
  Q = collections.deque([root])
  node = Q.popleft()	# 左出
  ```

  