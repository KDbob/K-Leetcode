//
// Created by kaide on 2021/5/8.
//
#include <stack>
#include <unordered_set>
#include "KStruct.h"

using namespace std;


/** 给定一个二叉树，找出其最大深度
 * 《DFS深度遍历（栈版本》
 * @param root 给定的二叉树根节点
 * @return 最大深度
 */
int maxDepth_stack(TreeNode *root) {
    stack<TreeNode *> stk;
    unordered_set<TreeNode *> seen;
    int maxDepth = 0;
    if (root) {
        stk.push(root);
        maxDepth++;
    }
    while (!stk.empty()) {
        TreeNode *top = stk.top();
        if (!top->left && !top->right) {
            stk.pop();
        } else if (top->left && !seen.count(top->left)) {
            stk.push(top->left);
            seen.insert(top->left);
            if (stk.size() > maxDepth) maxDepth = stk.size();
        } else if (top->right && !seen.count(top->right)) {
            stk.push(top->right);
            seen.insert(top->right);
            if (stk.size() > maxDepth) maxDepth = stk.size();
        } else {
            stk.pop();
        }
    }
    return maxDepth;
}

/** 给定一个二叉树，找出其最大深度
 * 《DFS深度遍历(递归版本)》
 * @param root 给定的二叉树根节点
 * @return 最大深度
 */
int maxDepth(TreeNode *root) {
    if (root) {
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return (leftMax > rightMax) ? leftMax + 1 : rightMax + 1;
    } else {
        return 0;
    }
}

int main() {
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // 栈的DFS：
    printf("maxDepth: %d\n", maxDepth_stack(tree));
    // 递归DFS：
    printf("maxDepth: %d\n", maxDepth(tree));
}