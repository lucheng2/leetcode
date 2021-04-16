class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n != 0:
            ans = ans+1 if n&1==1 else ans
            n = n>>1
        return ans
