import sys


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_stk, self.stk = [], []

    def push(self, x: int) -> None:
        self.stk.append(x)
        min = self.min_stk[-1]
        if min > x:
            self.min_stk.append(x)
        else:
            self.min_stk.append(min)

    def pop(self) -> None:
        self.stk.pop()
        self.min_stk.pop()

    def top(self) -> int:
        return self.stk[-1]

    def min(self) -> int:
        return self.min_stk[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
if __name__ == '__main__':
    stk = MinStack()
    stk.push(2)
    stk.push(0)
    stk.push(-3)
    print(stk.min())  # expect:-3
    stk.pop()
    print(stk.top())  # expect: 0
    print(stk.min())  # expect: 0
