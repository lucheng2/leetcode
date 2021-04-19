import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        lowest = prices[0]
        dp = [0] * n
        for i in range(1, n):
            lowest = min(lowest, prices[i])
            dp[i] = max(dp[i-1], prices[i] - lowest)
        return dp[n-1]


if __name__ == '__main__':
    s = Solution()
    p = [7,6,4,3,1]
    # p = [7,1,5,3,6,4]
    res = s.maxProfit(p)
    print(res)