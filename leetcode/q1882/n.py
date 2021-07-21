import heapq
from typing import List

class Node1():
    def __init__(self, w, _id, tm):
        self.w = w
        self._id = _id
        self.tm = tm

    def __lt__(self, other):
        if self.tm != other.tm:
            return self.tm < other.tm
        if self.w != other.w:
            return self.w < other.w
        return self._id < other._id


class Node2():
    def __init__(self, w, _id, tm):
        self.w = w
        self._id = _id
        self.tm = tm

    def __lt__(self, other):
        if self.w != other.w:
            return self.w < other.w
        return self._id < other._id

class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        heap1 = []
        heap2 = []
        ans = []

        for i in range(len(servers)):
            heapq.heappush(heap2, Node2(servers[i], i, 0))

        for i in range(len(tasks)):
            while len(heap1)>0 and heap1[0].tm<=i:
                heapq.heappush(heap2, Node2(heap1[0].w, heap1[0]._id, heap1[0].tm))
                heapq.heappop(heap1)

            if len(heap2) > 0:
                ans.append(heap2[0]._id)
                heapq.heappush(heap1, Node1(heap2[0].w, heap2[0]._id, i+tasks[i]))
                heapq.heappop(heap2)
            else:
                ans.append(heap1[0]._id)
                heapq.heappush(heap1, Node1(heap1[0].w, heap1[0]._id, heap1[0].tm+tasks[i]))
                heapq.heappop(heap1)
        return ans


