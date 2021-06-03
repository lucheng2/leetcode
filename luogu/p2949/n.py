from operator import itemgetter, attrgetter
import heapq

class node():
    def __init__(self, d, p):
        self.d = d
        self.p = p

    def __lt__(self, other):
        if self.p < other.p:
            return True
        else:
            return False

N = int(input().strip())
data = []
for i in range(N):
    a, b = map(int, input().strip().split())
    data.append(node(a, b))

data = sorted(data, key=attrgetter('d'))

pq = []
ans = 0

for i in range(N):
    if data[i].d <= len(pq):
        if pq[0].p < data[i].p:
            ans += data[i].p - pq[0].p
            heapq.heappop(pq)
            heapq.heappush(pq, data[i])
    else:
        heapq.heappush(pq, data[i])
        ans += data[i].p
print(ans)

