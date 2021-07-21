c = int(input().strip())
w = list(map(int, input().strip().split(',')))
v = list(map(int, input().strip().split(',')))

dp = [0 for i in range(c+1)] 

n = len(w)
for i in range(n):
    for j in range(c, w[i]-1, -1):
        dp[j] = max(dp[j], dp[j-w[i]] + v[i])

print(dp[c])

