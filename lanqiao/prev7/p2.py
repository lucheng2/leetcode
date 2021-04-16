N = int(input().strip())
data = list(map(int, input().strip().split()))
ans = 0
for i in range(len(data)):
    left = right = data[i]
    for j in range(i, len(data)):
        left = min(left, data[j])
        right = max(right, data[j])
        if right-left == j-i:
            ans += 1
print(ans)

