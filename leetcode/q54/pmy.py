from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        l, r, t, b = 0, n - 1, 0, m - 1
        total = m * n
        ans = []
        num = 0
        while num < total:
            for i in range(l, r + 1):
                if num < total:
                    ans.append(matrix[t][i])
                    num += 1
                else:
                    break
            t += 1
            for i in range(t, b + 1):
                if num < total:
                    ans.append(matrix[i][r])
                    num += 1
                else:
                    break
            r -= 1
            for i in range(r, l - 1, -1):
                if num < total:
                    ans.append(matrix[b][i])
                    num += 1
                else:
                    break
            b -= 1
            for i in range(b, t - 1, -1):
                if num < total:
                    ans.append(matrix[i][l])
                    num += 1
                else:
                    break
            l += 1
        return ans


if __name__ == '__main__':
    s = Solution()
    mat = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    ans = s.spiralOrder(mat)
    print(ans)
