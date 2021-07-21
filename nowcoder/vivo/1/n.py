data = list(map(int, input().strip().split()))

n = len(data)
cnt = 0

def check(a) -> bool:
    if a % 7 == 0:
        return True
    s = str(a)
    for i in range(len(s)):
        if s[i] == '7':
            return True
    return False

for i in range(n):
    if check(data[i]):
        cnt += 1

print(cnt)

