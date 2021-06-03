import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        min_int = - sys.maxsize

        dp = [[min_int for _ in range(n)], [0 for _ in range(n)]]
        dp[0][0] = - prices[0]
        dp[1][0] = 0
        for i in range(1, n):
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] - prices[i])
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i])

        return dp[1][n-1]