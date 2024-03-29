from PyUtils.kprint import print_linked_list, ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = None
        tail = None
        carry = 0
        while l1 or l2:
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0
            sum = n1 + n2 + carry
            if not head:
                head = tail = ListNode(sum % 10)
            else:
                tail.next = ListNode(sum % 10)
                tail = tail.next
            carry = sum // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry:
            tail.next = ListNode(1)
        return head


if __name__ == '__main__':
    list1 = ListNode(2, ListNode(4, ListNode(5)))
    list2 = ListNode(5, ListNode(6, ListNode(4)))
    s = Solution()
    results = s.addTwoNumbers(list1, list2)
    print_linked_list(results)
