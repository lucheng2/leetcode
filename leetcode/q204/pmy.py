class Solution:
    def countPrimes(self, n: int) -> int:
        ans = 0
        isPrime = [True] * n
        for i in range(2, n):
            if isPrime[i]:
                ans += 1
                for j in range(i * i, n, i):
                    isPrime[j] = False
        return ans
