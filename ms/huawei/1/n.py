def func():
    data = input().strip().split()
    n = len(data)
    total = 0
    for i in range(n):
        total += len(data[i])
    ans = round(total / i, 2)
    print(ans)
