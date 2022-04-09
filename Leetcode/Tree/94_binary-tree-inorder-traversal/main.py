from typing import List, Optional
from PyUtils.kstruct import TreeNode


class Solution(object):

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        《递归实现》
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

    def inorderTraversal2(self, root: Optional[TreeNode]) -> List[int]:
        """
        《迭代法》
        """
        res = []
        stk = []
        while root or stk:
            while root:
                stk.append(root)
                root = root.left
            root = stk.pop()
            res.append(root.val)
            root = root.right
        return res


if __name__ == '__main__':
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    result = Solution().inorderTraversal(root)
    print(result)
    result2 = Solution().inorderTraversal2(root)
    print(result2)
