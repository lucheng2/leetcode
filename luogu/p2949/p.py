from heapq import heappush, heappop
N = int(input().strip())
data = []
for i in range(1, N+1):
    d, p = map(int, input().strip().split())
    data.append([d, p])

data = sorted(data, key=lambda x: x[0])
ans = 0
pq = []
for i in range(0, N):
    if data[i][0] <= len(pq):
        if data[i][1] > pq[0]:
            ans += data[i][1] - heappop(pq)
            heappush(pq, data[i][1])
    else:
        ans += data[i][1]
        heappush(pq, data[i][1])
print(ans)
