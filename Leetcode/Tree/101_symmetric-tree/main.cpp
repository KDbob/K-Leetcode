// 101. 对称二叉树
// Created by kaide on 2021/5/11.
//
#include <iostream>
#include "KStruct.h"

using namespace std;


/**
 * 给定一个二叉树，检查它是否是镜像对称的（算子）
 * 《利用性质递归法》
 * @param lNode 互为镜像节点的左节点
 * @param rNode 互为镜像节点的右节点
 * @return 是否是对称
 */
bool valid(TreeNode *lNode, TreeNode *rNode) {
    if (lNode == nullptr && rNode == nullptr) return true;
    if (lNode == nullptr || rNode == nullptr) return false;
    if (lNode->val != rNode->val) return false;
    return valid(lNode->left, rNode->right) && valid(lNode->right, rNode->left);
}

bool isSymmetric(TreeNode* root) {
    return valid(root->left, root->right);
}

int main() {
//    1
//    / \
//  2   2
//  / \ / \
//3  4 4  3
    TreeNode *tree1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                                   new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    if (isSymmetric(tree1)) {
        printf("is symmetric\n");
    } else {
        printf("not symmetric\n");
    }
}