import sys
i = 1
ans = []
ceiling = 2**32
while i < ceiling:
    ans.append(i)
    i *= 3
print(ans)
