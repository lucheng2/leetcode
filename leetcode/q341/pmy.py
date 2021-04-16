class NestedInteger:
    def isInteger(self) -> bool:
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        """
        pass

    def getInteger(self) -> int:
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        """
        pass

    def getList(self) -> [NestedInteger]:
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        """
        pass


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.nestedList = nestedList
        self.size = len(nestedList) if nestedList else 0
        self.iterator = None
        self.i = 0
    
    def next(self) -> int:
        cur = self.nestedList[self.i]
        if cur.isInteger():
            self.i += 1
            return cur.getInteger()
        else: return self.iterator.next()
    
    def hasNext(self) -> bool:
        while self.i < self.size:
            cur = self.nestedList[self.i]
            if cur.isInteger(): return True
            else:
                if self.iterator == None:
                    self.iterator = NestedIterator(cur.getList())
                if self.iterator.hasNext(): return True
                else: 
                    self.iterator = None
                    self.i += 1
        return False
