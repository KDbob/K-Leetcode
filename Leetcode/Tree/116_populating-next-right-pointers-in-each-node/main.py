import collections
from typing import List


# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Tree:

    def buil_tree(self, level_order: List) -> Node:
        '''
        工具：通过层序遍历构建完美二叉树
        :param level_order:层序遍历
        :return: 完全二叉树
        '''
        n = len(level_order)

        def my_tree(level_indx):
            root = Node(level_order[level_indx])
            left_indx = level_indx * 2 + 1
            right_indx = level_indx * 2 + 2
            if left_indx < n:
                root.left = my_tree(left_indx)
            if right_indx < n:
                root.right = my_tree(right_indx)
            return root

        return my_tree(0)


class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        Q = collections.deque([root])
        while Q:
            level_num = len(Q)
            for i in range(level_num):
                node = Q.popleft()
                # 连接
                if i < level_num - 1:
                    node.next = Q[0]
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        return root


if __name__ == '__main__':
    level = [1, 2, 3, 4, 5, 6, 7, 8]
    tree = Tree().buil_tree(level)
    res = Solution().connect(tree)  # expect: tree with connected
    print(res)