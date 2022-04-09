from typing import List, Optional
from PyUtils.kstruct import TreeNode


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stk = []
        while root or stk:
            while root:
                stk.append(root)
                root = root.left
            root = stk.pop()
            k -= 1
            if k == 0:
                return root.val
            root = root.right


if __name__ == '__main__':
    root = TreeNode(3, TreeNode(1, None, TreeNode(2)), TreeNode(4))
    res = Solution().kthSmallest(root, 1)
    print(res)  # expect: 1
