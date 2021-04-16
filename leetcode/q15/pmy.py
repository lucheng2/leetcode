from collections import Counter
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)
        nums.sort()
        for first in range(0, n):
            if first>0 and nums[first]==nums[first-1]:
                continue
            target = -nums[first]
            r = n-1
            for l in range(first+1, n-1):
                if l > first+1 and nums[l]==nums[l-1]:
                    continue
                while l < r and nums[l]+nums[r]>target:
                    r -= 1
                if l==r:
                    break
                if nums[l]+nums[r] == target:
                    ans.append([-target, nums[l], nums[r]])
        return ans

