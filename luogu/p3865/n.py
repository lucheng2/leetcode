from math import log2

n, m = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
logn = 21
maxn = m + 1

f = [[0 for j in range(logn+1)] for i in range(maxn)]
for i in range(n):
    f[i+1][0] = a[i]

for j in range(1, logn+1):
    for i in range(1, n-(1<<j)+2):
        f[i][j] = max(f[i][j-1], f[i+(1<<j-1)][j-1])
for i in range(m):
    x, y = map(int, input().strip().split())
    s = int(log2(y-x+1))
    print("%d" % max(f[x][s],f[y-(1<<s)+1][s]))


