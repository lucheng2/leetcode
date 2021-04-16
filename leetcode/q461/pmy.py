class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        ans = 0
        for i in range(0, 32):
            if (x&1) ^ (y&1) == 1:
                ans += 1
            x >>= 1
            y >>= 1
        return ans
