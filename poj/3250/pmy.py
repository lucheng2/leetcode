tcase = int(input().strip())
data = []
for i in range(tcase):
    data.append(int(input().strip()))

priority_stack = []

ans = []
for i in range(tcase - 1, -1, -1):
    tmp = 0
    j = -1
    while len(priority_stack)>0 and priority_stack[-1] < data[i]:
        tmp += 1 + ans[j]
        j -= 1
        priority_stack.pop()
    ans.append(tmp)
    priority_stack.append(data[i])

total = sum(ans)
print(total)

