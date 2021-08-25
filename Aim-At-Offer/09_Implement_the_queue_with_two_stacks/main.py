# 剑指 Offer 09. 用两个栈实现队列
# Created by kaide on 2021/8/25.
#

class CQueue:

    def __init__(self):
        self.append_stk, self.delete_stk = [], []

    def appendTail(self, value: int) -> None:
        self.append_stk.append(value)

    def deleteHead(self) -> int:
        if self.delete_stk:
            return self.delete_stk.pop()
        if not self.append_stk:
            return -1
        while self.append_stk:
            self.delete_stk.append(self.append_stk.pop())
        return self.delete_stk.pop()


if __name__ == '__main__':
    q = CQueue()
    q.appendTail(3)
    print(q.deleteHead())  # expect: 3
    print(q.deleteHead())  # expect: -1
