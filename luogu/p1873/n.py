n, m = map(int, input().strip().split())
data = list(map(int, input().strip().split()))
limit = max(data)

def check(a) -> bool:
    cult = 0
    for i in range(len(data)):
        cult += max(0, data[i]-a)
        if cult >= m:
            return True
    return False

low = 0
high = limit

ans = 0
while low <= high:
    mid = (low+high) // 2
    if check(mid):
        ans = max(ans, mid)
        low = mid + 1
    else:
        high = mid - 1

print(ans)
