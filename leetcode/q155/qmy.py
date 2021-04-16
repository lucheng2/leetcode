class MinStack:

    def __init__(self):
        self.stack = []
        self.mstack = []


    def push(self, x: int) -> None:
        if self.mstack:
            self.mstack.append(min(self.mstack[-1], x))
        else:
            self.mstack.append(x)
        self.stack.append(x)


    def pop(self) -> None:
        self.mstack.pop()
        top = self.stack.pop()
        return top


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        return self.mstack[-1]
