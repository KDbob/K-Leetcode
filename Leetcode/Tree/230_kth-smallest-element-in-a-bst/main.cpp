//
// Created by bob on 2022/4/1.
// 230. 二叉搜索树中第K小的元素
#include <stack>
#include "KStruct.h"

using namespace std;

class Solution {
public:
    /**
     * 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）
     * 《中序遍历法》
     * @param root 根节点
     * @param k 第k个元素
     * @return
     */
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            k--;
            if (k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return root->val;
    }
};

int main() {
    TreeNode *tree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6));
    int res = Solution().kthSmallest(tree, 3);
    printf("%d", res);  //expect: 3
}