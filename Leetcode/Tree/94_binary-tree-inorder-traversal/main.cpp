//
// Created by bob on 2022/1/20.
//

#include "vector"
#include "KStruct.h"

using namespace std;

class Soulution {
public:

    void traversal(TreeNode *node, vector<int> &res) {
        if (!node) {
            return;
        }
        traversal(node->left, res);
        res.push_back(node->val);
        traversal(node->right, res);
    }

    /**
     * 给定一个二叉树的根节点 root ，返回它的 中序 遍历
     * @param root 二叉树的根结点
     * @return
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};


int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Soulution solution = Soulution();
    vector<int> res = solution.inorderTraversal(root);
}