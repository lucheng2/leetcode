while True:
    n, u, d = map(int, input().strip().split())
    if n == 0:
        break
    time = 0
    dist = 0
    while True:
        dist += u
        time += 1
        if dist >= n:
            break
        dist -= d
        time += 1
    print(time)

