n = int(input().strip())

f = [0] * (n + 1)
for i in range(1, n+1):
    f[i] = i

def find(i):
    if f[i] == i:
        return i
    else:
        f[i] = find(f[i])
        return f[i]

def union(i, j):
    x = find(i)
    y = find(j)
    f[x] = y
k = int(input().strip())
for i in range(k):
    a, b = map(int, input().strip().split())
    union(a, b)
    
hm = {}
for i in range(1, n+1):
    p = find(i)
    if p in hm:
        hm[p] += 1
    else:
        hm[p] = 1
print(max(hm.values()))
