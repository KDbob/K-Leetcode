from typing import List

from PyUtils.kstruct import TreeNode


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def my_tree(preorder_index, inorder_left_index, inorder_right_index):
            preorder_value = preorder[preorder_index]
            inorder_root_index = inorder.index(preorder_value)
            left_len = inorder_root_index - inorder_left_index
            right_len = inorder_right_index - inorder_root_index
            node = TreeNode(preorder_value)
            if left_len > 0:
                node.left = my_tree(preorder_index + 1, inorder_left_index, inorder_root_index - 1)
            if right_len > 0:
                node.right = my_tree(preorder_index + 1 + left_len, inorder_root_index + 1, inorder_right_index)
            return node
        return my_tree(0, 0, len(inorder)-1)

if __name__ == '__main__':
    preorder = [1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 7]
    inorder = [8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 3, 7]
    s = Solution()
    tree = s.buildTree(preorder, inorder)
    print(tree)