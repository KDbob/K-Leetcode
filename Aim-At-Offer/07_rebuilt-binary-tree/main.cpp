// 剑指 Offer 07. 重建二叉树
// Created by kaide on 2021/3/20.
//
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *myTree(vector<int> &preorder, vector<int> &inorder, int preLeftIndx, int leftOrderIndx, int rightOrderIndx) {
    int inorderIndex = map[preorder[preLeftIndx]];
//    int length = inorderIndex - preLeftIndx;    // 这个计算是完全错误的
    int leftLength = inorderIndex - leftOrderIndx;
    int rightLength = rightOrderIndx - inorderIndex;
    TreeNode *root = new TreeNode(preorder[preLeftIndx]);
    if (leftLength>0) {
        root->left = myTree(preorder, inorder, preLeftIndx + 1, leftOrderIndx, inorderIndex - 1);
    }
    if (rightLength>0) {
        root->right = myTree(preorder, inorder, preLeftIndx + 1 + leftLength, inorderIndex + 1, rightOrderIndx);
    }
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
    return myTree(preorder, inorder, 0, 0, n-1);
}

int main() {
//    vector<int> pre = {3, 9, 20, 15, 7};
//    vector<int> in = {9,3,15,20,7};
    vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 7};
    vector<int> in = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 3, 7};
    TreeNode *tree = buildTree(pre, in);
    return 0;
}