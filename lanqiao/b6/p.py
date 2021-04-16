n = int(input().strip())
if n == 1:
    print(1)
else:
    ans = []
    ans.append([1])
    for i in range(1, n):
        tmp = [1]
        for j in range(1, i+1):
            if j== i:
                tmp.append(1)
            else:
                tmp.append(ans[i-1][j-1]+ans[i-1][j])
        ans.append(tmp)
    for i in range(len(ans)):
        print(" ".join(map(str, ans[i])))

