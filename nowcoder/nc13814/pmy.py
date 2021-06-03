data = []
hm = {'zero': '0', 'two': '2', 'four': '4', 'six': '6', 'nine': '9'}
st = ['0', '2', '4', '6', '9']

tcase = int(input().strip())
for i in range(tcase):
    a = input().strip()
    data.append(a)

ans = ['' for _ in range(len(data))]

for i in range(len(data)):
    j = 0
    n = len(data[i])
    while j < n:
        if data[i][j] in st:
            ans[i] += data[i][j]
        else:
            if data[i][j: j+3] in hm:
                ans[i] += hm[data[i][j: j+3]]
                j += 2
            elif data[i][j: j+4] in hm:
                ans[i] += hm[data[i][j: j+4]]
                j += 3
        j += 1

for i in range(len(ans)):
    print(ans[i])


