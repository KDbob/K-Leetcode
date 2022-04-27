//
// Created by bob on 2022/4/24.
//
#include<vector>
#include<queue>
#include "KStruct.h"

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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool isOrderLeft = true;    // 偶数层，结果队列是从左至右

        while (!q.empty()) {
            deque<int> leveList;
            int currentLayerNum = q.size();
            for (int i = 0; i < currentLayerNum; ++i) {
                auto node = q.front();
                q.pop();
                if (isOrderLeft) {
                    leveList.push_back(node->val);
                } else {
                    leveList.push_front(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(vector<int>{leveList.begin(), leveList.end()});
            isOrderLeft = !isOrderLeft;
        }
        return res;
    }
};

int main() {
//    3
//    / \
//  9  20
//     /  \
//   15   7
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> res = Solution().zigzagLevelOrder(tree);
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
//    [20,9],
//    [15,7,],
//    ],
}