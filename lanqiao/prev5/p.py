n = int(input().strip())
data = []
for i in range(n):
    tmp = list(map(int, input().strip().split()))
    for d in tmp:
        data.append(d)

data.sort()
for i in range(1, len(data)):
    if data[i] == data[i-1]:
        repet = data[i]
    elif data[i] != data[i-1] + 1:
        loss = data[i-1] + 1
print(loss, repet)

