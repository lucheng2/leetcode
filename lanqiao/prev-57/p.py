s = input().strip()
ans = 0
n = len(s)
for i in range(n):
    st = set()
    for j in range(i, n):
        st.add(s[j])
        ans += len(st)
print(ans)
