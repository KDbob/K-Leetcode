# 21. 合并两个有序链表
# Created by kaide on 2021/7/4.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists1(l1: ListNode, l2: ListNode) -> ListNode:
    """
    将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
    《方法一：递归构建》
    :param l1: 链表1
    :param l2: 链表2
    :return: 合并后新的升序链表
    """
    if not l1 or not l2:
        if not l1:
            return l2
        if not l2:
            return l1
    if l1.val < l2.val:
        l1.next = mergeTwoLists1(l1.next, l2)
        return l1
    else:
        l2.next = mergeTwoLists1(l1, l2.next)
        return l2


def mergeTwoLists2(l1: ListNode, l2: ListNode) -> ListNode:
    """
    将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
    《方法二：迭代法》
    :param l1: 链表1
    :param l2: 链表2
    :return: 合并后新的升序链表
    """
    prehead = ListNode(-1)
    prev = prehead
    while (l1 and l2):
        if l1.val < l2.val:
            prev.next = l1
            l1 = l1.next
        else:
            prev.next = l2
            l2 = l2.next
        prev = prev.next
    prev.next = l1 if l1 else l2
    return prehead.next


def test(l: ListNode):
    while l:
        print("->{}".format(l.val), end="")
        l = l.next
    print()


if __name__ == '__main__':
    head1 = ListNode(1, next=ListNode(2, next=ListNode(4)))  # ->1->2->4
    head2 = ListNode(1, next=ListNode(3, next=ListNode(4)))  # ->1->3->4
    l1 = mergeTwoLists1(head1, head2)
    test(l1)  # expect:->1->1->2->3->4->4

    head3 = ListNode(1, next=ListNode(2, next=ListNode(4)))  # ->1->2->4
    head4 = ListNode(1, next=ListNode(3, next=ListNode(4)))  # ->1->3->4
    l2 = mergeTwoLists2(head3, head4)
    test(l2)
