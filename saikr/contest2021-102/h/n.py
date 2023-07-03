import math

def comp(n) -> bool:
    a = math.sqrt(n) 
    a = int(a)
    return a*a == n

def h(n) -> bool:
    for i in range(2, n):
        if n % i == 0:
            if comp(n*i):
                return True
            
    return False

ans = []
i = 2
while True:
    if h(i):
        ans.append(i)
    if len(ans) == 3000:
        print(ans[-1])
        break
    i += 1

    
