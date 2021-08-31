from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        li = list()
        while head:
            li.append(head.val)
            head = head.next
        res = list()
        while li:
            res.append(li.pop())
        return res


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(3)
    head.next.next = ListNode(2)

    solution = Solution()
    print(solution.reversePrint(head))
