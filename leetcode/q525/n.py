class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        presum = 0
        hm = {}
        hm[0] = -1
        ans = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                presum -= 1
            else:
                presum += 1
            if presum in hm:
                ans = max(ans, i - hm[presum])
            else:
                hm[presum] = i
        return ans

