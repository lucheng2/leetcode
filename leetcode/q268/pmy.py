from collections import Counter
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        c = Counter()
        c.update(nums)
        for i in range(0, len(nums) + 1):
            if not c.get(i):
                return i
