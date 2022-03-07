from PyUtils.kstruct import ListNode


def print_linked_list(l: ListNode):
    while l:
        print("->{}".format(l.val), end="")
        l = l.next
    print()
