from PyUtils.kstruct import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """双指针法"""
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        tempA = headA
        tempB = headB
        while tempA != tempB:
            tempA = tempB if tempA is None else tempA.next
            tempB = tempA if tempB is None else tempB.next
        return tempA


if __name__ == '__main__':
    cross_list = ListNode(8, ListNode(4, ListNode(5)))
    listA = ListNode(4, ListNode(1, cross_list))
    listB = ListNode(5, ListNode(6, ListNode(1, cross_list)))
    s = Solution()
    node = s.getIntersectionNode(listA, listB)
    print(node.val)  # expect: 8
