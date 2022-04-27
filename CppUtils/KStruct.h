//
// Created by bob on 2021/11/16.
//

#ifndef K_LEETCODE_KSTRUCT_H
#define K_LEETCODE_KSTRUCT_H

#include <vector>
#include <unordered_map>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

} ListNode;


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;


class Tree {
private:
    unordered_map<int, int> map;

    TreeNode *myTree(vector<int> &preorder, int preorderIndex, int inorderLeftIndex, int inorderRightIndex);

    TreeNode *myTree(vector<int> &levelorder, int levelIndex);

public:
    /**
     * 前序+中序构造二叉树（普通二叉树）
     * @param preorder 前序数组
     * @param inorder 中序数组
     * @return 构造而成的二叉树的根节点
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

    /**
     * 层序构造完全二叉树
     * @param levelorder 层序数组
     * @return 构造而成的二叉树的根节点
     */
    TreeNode *buildTree(vector<int> &levelorder);
};

#endif //K_LEETCODE_KSTRUCT_H
