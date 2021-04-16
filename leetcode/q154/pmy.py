#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        ans = nums[0]
        i = 1
        while i < n:
            if nums[i] < ans:
                return nums[i]
            i += 1
        return ans

