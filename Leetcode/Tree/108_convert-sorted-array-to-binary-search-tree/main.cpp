//
// Created by kaide on 2021/5/18.
//
#include <vector>

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
 * 通过一个搜索二叉树的中序遍历，将其转换为一棵 高度平衡 二叉搜索树
 * @param nums 整数数组
 * @param left 子树在数组的范围（左游标）
 * @param right 子树在数组的范围（右游标）
 * @return 高度平衡 二叉搜索树
 */
TreeNode *structTree(vector<int> &nums, int left, int right) {
    if (left>right) {
        return nullptr;
    }
    int mid = (left + right + 1) / 2; // 总是选择中间位置靠右作为根节点
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = structTree(nums, left, mid - 1);
    root->right = structTree(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    return structTree(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *new_tree = sortedArrayToBST(nums);
    printf("%p", &new_tree);
}