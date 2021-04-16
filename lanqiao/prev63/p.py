n = int(input().strip())
data = []
for i in range(n):
    tmp = int(input().strip())
    data.append(tmp)
jige = 0
youxiu = 0
for i in range(n):
    if data[i] >= 85:
        jige += 1
        youxiu += 1
    elif data[i] >= 60:
        jige += 1
print(str(round(jige / len(data) * 100) ) + '%')
print(str(round(youxiu / len(data) * 100)) + '%')
