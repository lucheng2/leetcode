class MinStack:

    def __init__(self):
        self.stack = []
        self.min_num = -1


    def push(self, x: int) -> None:
        if not self.stack:
            self.stack.append(0)
            self.min_num = x
        else:
            diff = x - self.min_num
            self.stack.append(diff)
            if diff < 0:
                self.min_num = x


    def pop(self) -> None:
        if self.stack:
            diff = self.stack.pop()
            if diff < 0:
                top = self.min_num
                self.min_num = self.min_num - diff
            else:
                top = diff + self.min_num
        return top


    def top(self) -> int:
        if self.stack:
            diff = self.stack[-1]
            if diff < 0:
                top = self.min_num
            else:
                top = self.min_num + diff
        return top


    def getMin(self) -> int:
        return self.min_num
