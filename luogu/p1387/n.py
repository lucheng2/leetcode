n, m = map(int, input().strip().split())
data = [ [0 for i in range(m+1)] for j in range(n+1) ]
presum = [ [0 for i in range(m+1)] for j in range(n+1) ]

for i in range(1, n+1):
    tmp = list(map(int, input().strip().split()))
    for j in range(1, m+1):
        data[i][j] = tmp[j-1]
        presum[i][j] = presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1] + data[i][j]

ans = 1
l = 2
while l<=min(n,m):
    for i in range(l, n+1):
        for j in range(l, m+1):
            if presum[i][j]-presum[i-l][j]-presum[i][j-l]+presum[i-l][j-l] == l*l:
                ans = max(ans, l)
    l += 1

print(ans)


        
