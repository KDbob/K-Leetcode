//
// Created by bob on 2022/1/20.
//

#include <vector>
#include <stack>
#include "KPrint.h"

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
     * 《递归法》
     * @param root 二叉树的根结点
     * @return
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    /**
     * 给定一个二叉树的根节点 root ，返回它的 中序 遍历
     * 《迭代法》
     * @param root
     * @return
     */
    vector<int> inorderTraversal2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};


int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    vector<int> res = Soulution().inorderTraversal(root);
    printVector(res);
    vector<int> res2 = Soulution().inorderTraversal2(root);
    printVector(res2);
}