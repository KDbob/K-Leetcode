// 102. 二叉树的层序遍历
// Created by kaide on 2021/5/13.
//
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值
 * 《队列实现BFS法：精简》
 * @param root 二叉树的根节点
 * @return 层序遍历的vector数组
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode *> q;
    q.push({root});
    while (!q.empty()) {
        int currentLayerNum = q.size();
        res.push_back(vector<int>());
        for (int i=0; i<currentLayerNum; i++) {
            TreeNode *n = q.front();
            q.pop();
            res.back().push_back(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
    }
    return res;
}


int main() {
//    3
//    / \
//  9  20
//     /  \
//   15   7
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> res = levelOrder(tree);
    printf("[\n");
    for(auto l:res) {
        printf("\t[");
        for (auto r:l) {
            printf("%d,", r);
        }
        printf("],\n");
    }
    printf("],");
    // expect:
//    [
//    [3,],
//    [9,20,],
//    [15,7,],
//    ],
}