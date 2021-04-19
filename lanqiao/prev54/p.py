m, n = map(int, input().strip().split())
cel = m * n

f = [0] * (cel + 1)
for i in range(1, cel+1):
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

s = set()
for i in range(1, cel+1):
    s.add(find(i))
print(len(s))
