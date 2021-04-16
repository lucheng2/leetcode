import bisect
N = int(input().strip())
data = list(map(int, input().strip().split()))
ans = 0
sd = []
for i in range(N):
    for j in range(len(sd)):
        bisect.insort(sd[j], data[i])
        if sd[j][-1] - sd[j][0] == len(sd[j]) - 1:
            ans += 1
    sd.append([data[i]])
    ans += 1
print(ans)
