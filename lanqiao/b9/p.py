n = int(input().strip())
if n < 2:
    print()
ans = []
ans6= []
for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            if i*2 + j*2 + k == n:
                ans.append(str(i)+str(j)+str(k)+str(j)+str(i))
            if i*2 + j*2 + k*2 == n:
                ans6.append(str(i)+str(j)+str(k)+str(k)+str(j)+str(i))
for i in range(len(ans)):
    print(ans[i])
for i in range(len(ans6)):
    print(ans6[i])
