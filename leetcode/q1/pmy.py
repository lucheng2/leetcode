import bisect
from typing import List
from _collections import defaultdict


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        dd = defaultdict(lambda: 'N/A')
        for i in range(0, n):
            if dd[target - nums[i]] != 'N/A':
                return [dd[target - nums[i]], i]
            else:
                dd[nums[i]] = i
        return [0, 0]


if __name__ == '__main__':
    s = Solution()
    nums = [3,2,4]
    target = 6
    ans = s.twoSum(nums, target)
    print(ans)
