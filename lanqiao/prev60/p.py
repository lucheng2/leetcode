N = int(input().strip())
def check1(n):
    n = str(n)
    if len(n) == 8:
        if n[:4] == n[4:][::-1]:
            return True
    return False
def check2(n):
    n = str(n)
    if len(n) == 8:
        if check1(n) and n[0]==n[2] and n[1]==n[3] and not n[0]==n[1]:
            return True
    return False
big = ['01', '03', '05', '07', '08', '10', '12']
small = ['04', '06', '09', '11']
specila = '02'
def check3(n):
    n = str(n)
    month = ''.join(n[4:6])
    day = ''.join(n[6:])
    if month in big and day <= '31':
        return True
    elif month in small and day <= '30':
        return True
    elif month == specila:
        year = int(n[:4])
        if (year%4==0 and not year%100==0) or year%400==0:
            if day <= '29':
                return True
            else:
                return False
        else:
            if day <= '28':
                return True
            else:
                return False
    return False

n = N // 1000000
for i in range (n+1

for i in range(N+1, 99999999+1):
    if check3(i) and check1(i):
        print(i)
        break
N = i
for i in range(N, 99999999):
    if check3(i) and check2(i):
        print(i)
        break
