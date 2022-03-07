from PyUtils.kstruct import TreeNode


class Solution(object):

    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []

        def traversal(node):
            if node == None:
                return
            traversal(node.left)
            res.append(node.val)
            traversal(node.right)

        traversal(root)
        return res


if __name__ == '__main__':
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    result = Solution().inorderTraversal(root)
    print(result)
