# 点
class Point(object):

    def __init__(self, x, y):
        self.x, self.y = x, y

# 向量
class Vector(object):

    def __init__(self, start_point, end_point):
        self.start, self.end = start_point, end_point
        self.x = end_point.x - start_point.x
        self.y = end_point.y - start_point.y

ZERO = 1e-9

def negative(vector):
    """取反"""
    return Vector(vector.end, vector.start)

def vector_product(vectorA, vectorB):
    '''计算 x_1 * y_2 - x_2 * y_1'''
    return vectorA.x * vectorB.y - vectorB.x * vectorA.y

def is_intersected(A, B, C, D):
    '''A, B, C, D 为 Point 类型'''
    AC = Vector(A, C)
    AD = Vector(A, D)
    BC = Vector(B, C)
    BD = Vector(B, D)
    CA = negative(AC)
    CB = negative(BC)
    DA = negative(AD)
    DB = negative(BD)

    return (vector_product(AC, AD) * vector_product(BC, BD) <= ZERO) \
        and (vector_product(CA, CB) * vector_product(DA, DB) <= ZERO)

def solve():
    n, m = map(int ,input().strip().split())
    if n<2 or m <2:
        print("NO")
        return
        
    red = []
    yellow = []
    for i in range(n):
        x, y = map(int, input().strip().split())
        red.append([x, y])
        
    for i in range(m):
        x, y = map(int, input().strip().split())
        yellow.append([x, y])

    red.sort()
    yellow.sort()
    for i in range(n):
        j = i+1
        for k in range(m):
            l = k + 1
            A = Point(red[i][0], red[i][1])
            B = Point(red[j][0], red[j][1])
            C = Point(yellow[k][0], yellow[k][1])
            D = Point(yellow[l][0], yellow[l][1])

            if is_intersected(A, B, C, D):
                print("YES")
                return
    print("NO")
solve()
