S = input().strip()

def f(hm):
    ans = 0
    for key in hm:
        if hm[key] == 1:
            ans += 1
    return ans

n = len(S)
ret = 0
for i in range(n):
    hm = {}
    for j in range(i, n):
        if S[j] in hm:
            hm[S[j]] += 1
        else:
            hm[S[j]] = 1
        ret += f(hm)
print(ret)

