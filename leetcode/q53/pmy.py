from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = nums.copy()
        n = len(nums)
        ans = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i], dp[i-1] + dp[i])
            ans = max(ans, dp[i])
        return ans


if __name__ == '__main__':
    s = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    ans = s.maxSubArray(nums)
    print(ans)
