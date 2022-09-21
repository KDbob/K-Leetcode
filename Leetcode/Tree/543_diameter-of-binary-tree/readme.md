#### [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/)

> 树、DFS

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

**示例 :**
给定二叉树

```
          1
         / \
        2   3
       / \     
      4   5    
```

返回 **3**, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

**注意：**两结点之间的路径长度是以它们之间边的数目表示。

# 方法一：DFS

类似[104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

## 解题思路

![说明图](https://pic.leetcode-cn.com/f39419c0fd3b3225a643ac4f40a1289c93cb03a6fb07a0be9e763c732a49b47d-543.jpg)

> *L* （即以左儿子为根的子树的深度）,*R* （即以右儿子为根的子树的深度）

- 该节点为起点的路径经过节点的最大值为：L+R+1

  >  （2+3+1=6）指的节点数

- 题目所求所有二叉树的最大路径：即所有节点的最大值-1

  > 指的路径数=5

做法：在DFS的过程中，对每个节点计算最大路径，遍历完成后取最大值