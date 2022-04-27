from typing import List
from PyUtils.kstruct import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        even_head = head.next
        odd_ptr, even_ptr = head, even_head
        while even_ptr and even_ptr.next:
            odd_ptr.next = even_ptr.next
            odd_ptr = odd_ptr.next
            even_ptr.next = odd_ptr.next
            even_ptr = even_ptr.next
        odd_ptr.next = even_head
        return head


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    res = Solution().oddEvenList(head)
    print(res)  # expect: 1,3,5,2,4
