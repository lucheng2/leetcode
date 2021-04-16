ans = []
for i in range(1, 10):
    for j in range(0, 10):
        ans.append(str(i)+str(j)+str(j)+str(i))
for i in range(len(ans)):
    print(ans[i])
