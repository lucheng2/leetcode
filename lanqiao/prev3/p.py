# n = int(input().strip())
from collections import Counter
men = []
for n in range(100, 101):
    ans = 0
    for i in range(1, n+1):
        for j in range(1, 100_0000_0000):
            for k in range(1, 100_0000_0000):
                if i + j / k == n:
                    s = str(i) + str(j) + str(k)
                    c = Counter(s)
                    for key in range(ord('1'), ord('1') + 10):
                        if not c.get(chr(key)) == 1:
                            break
                    ans += 1
    men.append(ans)
print(men)
