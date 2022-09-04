// 543. 二叉树的直径
// Created by bob on 2022/7/29.
//
#include "KStruct.h"
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res;

    int maxDepth(TreeNode *root) {
        if (root) {
            int L = maxDepth(root->left);
            int R = maxDepth(root->right);
            res = max(res, L + R + 1);
            return L > R ? L + 1 : R + 1;
        } else {
            return 0;
        }
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        res = 1;
        maxDepth(root);
        return res - 1;
    }
};

int main() {
   //    1
   //   / \
   //  2   3
   // / \
   //4   5

    TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

    int res = Solution().diameterOfBinaryTree(tree);
    printf("%d", res);

    return 0;
}