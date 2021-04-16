word = input().strip()
a = ord('a')
hm = [0] * 26
for c in word:
    hm[ord(c) - a] += 1
mx = 0
for i in range(26):
    if hm[mx] < hm [i]:
        mx = i
print(chr(mx + a))
print(hm[mx])
