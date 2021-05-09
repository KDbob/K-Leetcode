// 98. 验证二叉搜索树
// Created by kaide on 2021/5/9.
//
#include <iostream>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/** 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 《递归（利用性质）》
 * @param node 二叉树的节点
 * @param lower 节点值的取值范围：下界
 * @param upper 节点值的取值范围：上界
 * @return 是否有效的二叉树
 */
bool valid(TreeNode *node, int lower, int upper) {
    if (node == nullptr) {
        return true;
    }
    if (node->val <=lower || node->val >= upper) {
        return false;
    }
    return valid(node->left, lower, node->val) && valid(node->right, node->val, upper);
}


bool isValidBST(TreeNode *root) {
    return valid(root, INT_MIN, INT_MAX);
}


int main() {
//  1
//  ｜
//  1
//    TreeNode *tree = new TreeNode(1, new TreeNode(1), new TreeNode());
//    if (isValidBST(tree)) {
//        printf("is valid BST\n");
//    } else {
//        printf("not valid BST\n");
//    }
//    2
//    / \
//  1   3
//    TreeNode *tree1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
//    if (isValidBST(tree1)) {
//        printf("is valid BST\n");
//    } else {
//        printf("not valid BST\n");
//    }
//    5
//    / \
//  1   4
//      / \
//    3   6
    TreeNode *tree2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    if (isValidBST(tree2)) {
        printf("is valid BST\n");
    } else {
        printf("not valid BST\n");
    }
}