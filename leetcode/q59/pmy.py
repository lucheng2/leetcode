from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        l, r, t, b = 0, n-1, 0, n-1
        total = n * n
        count = 1
        while count <= total:
            for i in range(l, r+1):
                matrix[t][i] = count
                count += 1
            t += 1
            for i in range(t, b+1):
                matrix[i][r] = count
                count += 1
            r -= 1
            for i in range(r, l-1, -1):
                matrix[b][i]= count
                count += 1
            b -= 1
            for i in range(b, t -1 , -1):
                matrix[i][l] = count
                count += 1
            l += 1
        return matrix
