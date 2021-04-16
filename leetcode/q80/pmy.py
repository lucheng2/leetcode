class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n
        i = 0
        j = 1
        single = True
        while j < n:
            if nums[j] != nums[j-1] :
                if single:
                    nums[i] = nums[j-1]
                    i += 1
                else:
                    nums[i] = nums[j-1]
                    nums[i+1] = nums[j-1]
                    i += 2
                single = True
            else:
                single = False
            j += 1
        if single:
            nums[i] = nums[j-1]
            i += 1
        else:
            nums[i] = nums[j-1]
            nums[i+1] = nums[j-1]
            i += 2
        return i




