def check(mid) -> bool:
    f = [-1e9] * (W+1)
    f[0] = 0
    for i in range(N):
        for j in range(W, -1, -1):
            k = min(W, j+w[i])
            f[k] = max(f[k], f[j]+t[i]-mid*w[i])
    return f[W] > 0

N, W = map(int, input().strip().split())
w = []
t = []
for i in range(N):
    a, b = map(int, input().strip().split())
    w.append(a)
    t.append(b)
low = 0
high = 1e6
eps = 1e-4
ans = 0
while high-low>eps:
    mid = (high+low) / 2
    if check(mid):
        ans = max(ans, mid)
        low = mid
    else:
        high = mid
        
ans = int(1000*ans)
print(ans)





