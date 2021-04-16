n, m = map(int, input().strip().split() )
data = [[0 for i in range(m)] for i in range(n)]
a = ord('A')
for i in range(m):
    data[0][i] = chr(a+i)
for i in range(1, n):
    data[i][0] = chr(ord(data[i-1][0]) + 1)
    for j in range(1, m):
        data[i][j] = data[i-1][j-1]
for i in range(n):
    print("".join(data[i]))

