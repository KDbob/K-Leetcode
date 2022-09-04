// 235. 二叉搜索树的最近公共祖先
// Created by bob on 2022/8/8.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<TreeNode*> getPath(TreeNode *node, TreeNode *target) {
        vector<TreeNode *> path;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> path_p = getPath(root, p);
        vector<TreeNode *> path_q = getPath(root, q);
        TreeNode *res;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_q[i] == path_p[i]) {
                res = path_q[i];
            } else {
                break;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}