
sn = {}
an = {}
sn[1] = 1
sn[2] = 2
an[1] = 1
an[2] = 2

def sn(n):
    global sn
    if n < 3:
        return sn[n]
    sn[n] = sn[n-1] + sn[n-2]

    
def fun(n, p):
    pass
