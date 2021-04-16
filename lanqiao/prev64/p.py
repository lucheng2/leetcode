n = int(input().strip())
data = []
for i in range(n):
    tmp = int(input().strip())
    data.append(tmp)

print(max(data))
print(min(data))
s = sum(data)
avg = s / len(data)
print("%.2f" % avg)
