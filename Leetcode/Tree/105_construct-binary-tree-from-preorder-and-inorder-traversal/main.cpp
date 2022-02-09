//
// Created by bob on 2022/1/21.
//
#include <vector>
#include <unordered_map>
#include "KStruct.h"
#include "KPrint.h"

using namespace std;

class Solution {
private:
    unordered_map<int,int> map;
    /**
     *
     * @param preorder 中序遍历数组
     * @param preorderIndex 前序的节点的索引
     * @param inorderLeftIndex 中序的起始位置（递归构造哪部分子树）
     * @param inorderRightIndex 中序的结束位置
     * @return 构造好的二叉树
     */
    TreeNode *myTree(vector<int> &preorder, int preorderIndex, int inorderLeftIndex, int inorderRightIndex) {
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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size() - 1;
        for (int i = 0; i < n; ++i) {
            map[inorder[i]] = i;
        }
        return myTree(preorder, 0, 0, n - 1);
    }
};

int main() {
    vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 7};
    vector<int> in = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 3, 7};
    Solution solution = Solution();
    TreeNode *tree = solution.buildTree(pre, in);   // expect level order: 1 2 3 4 5 6 7 8
    printf("%p",tree);
}