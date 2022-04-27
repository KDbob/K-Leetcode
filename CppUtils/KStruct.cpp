#include "KStruct.h"

TreeNode *Tree::myTree(vector<int> &preorder, int preorderIndex, int inorderLeftIndex, int inorderRightIndex) {
    int inorderRootIndex = map[preorder[preorderIndex]];
    int leftLength = inorderRootIndex - inorderLeftIndex;
    int rightLength = inorderRightIndex - inorderRootIndex;
    TreeNode *root = new TreeNode(preorder[preorderIndex]);
    if (leftLength > 0) {
        root->left = myTree(preorder, preorderIndex + 1, inorderLeftIndex, inorderRootIndex - 1);
    }
    if (rightLength > 0) {
        root->right = myTree(preorder, preorderIndex + 1 + leftLength, inorderRootIndex + 1,
                             inorderRootIndex);
    }
    return root;
}



TreeNode *Tree::myTree(vector<int> &levelorder, int levelIndex) {
    TreeNode *root = new TreeNode(levelorder[levelIndex]);
    int leftIndex = levelIndex * 2 + 1;
    int rightIndex = levelIndex * 2 + 2;
    if (leftIndex < levelorder.size()) {
        root->left = myTree(levelorder, leftIndex);
    }
    if (rightIndex  < levelorder.size()) {
        root->right = myTree(levelorder, rightIndex);
    }
    return root;
}


TreeNode *Tree::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size() - 1;
    for (int i = 0; i < n; ++i) {
        map[inorder[i]] = i;
    }
    return myTree(preorder, 0, 0, n - 1);
}

/**
 * 通过层序构建完全二叉树
 * @param levelorder
 * @return
 */
TreeNode *Tree::buildTree(vector<int> &levelorder) {
    return myTree(levelorder, 0);
}