def check(mid) -> bool:
    c = []
    for i in range(n):
        c.append(a[i] - mid*b[i])
    c = sorted(c)
    s = 0
    for i in range(k, n):
        s += c[i]
    return s>0

while True:
    n, k = map(int, input().strip().split())
    if n==0:
        break
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    low = 0
    high = 1
    eps = 0.0000001
    ans = 0
    while high-low>eps:
        mid = (high+low)/2
        if check(mid):
            ans = max(mid, ans)
            low = mid
        else:
            high = mid
    ans = round(ans*100)
    print("%d" % ans)




