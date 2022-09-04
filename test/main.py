class ListNode(object):

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


if __name__ == '__main__':

    while True:
        try:
            # 构建链表
            n = input()
            s = input()
            k = input()
            items = s.split(" ")
            ll = ListNode()
            head = ll
            for i in range(n):
                ll.next = ListNode(items[i])
                ll = ll.next
            head = head.next
            #
            fast = head
            slow = head
            while k:
                fast = fast.next
                k = k - 1
            while fast:
                fast = fast.next
                slow = slow.next
            print(slow.val)
        except:
            break