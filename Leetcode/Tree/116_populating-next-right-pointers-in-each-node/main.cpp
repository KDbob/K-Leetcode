// 116. 填充每个节点的下一个右侧节点指针
// Created by bob on 2022/4/25.
//
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* myTree(vector<int> &levelorder, int levelIndex) {
    Node *root = new Node(levelorder[levelIndex]);
    int leftIndex = levelIndex * 2 + 1;
    int rightIndex = levelIndex * 2 + 2;
    if (leftIndex < levelorder.size()) {
        root->left = myTree(levelorder, leftIndex);
    }
    if (rightIndex < levelorder.size()) {
        root->right = myTree(levelorder, rightIndex);
    }
    return root;
}

/**
 * 通过层序构建完全二叉树（完美二叉树）
 */
Node* buildTree(vector<int> &levelorder) {
    return myTree(levelorder, 0);
}


class Solution {
public:
/**
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * @param root 完美二叉树
 * @return  连接后的完美二叉树
 */
Node* connect(Node* root) {
    if (root == nullptr) {
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLayerNum = q.size();
        for (int i = 0; i < currentLayerNum; ++i) {
            Node *n = q.front();
            // 连接
            q.pop();
            if (i < currentLayerNum -1) {
                n->next = q.front();
            }
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
    }
    return root;
}
};



int main() {
    vector<int> level = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root = buildTree(level);
    Node *res = Solution().connect(root);   // expect: connected
    return 0;
}