n = int(input().strip())
for i in range(n):
    hx = int(input().strip(), base=16)
    print(oct(hx)[2:])
