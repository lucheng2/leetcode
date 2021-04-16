class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <3:
            return False
        priority_stack = []
        priority_stack.append(nums[-1])
        max_k = float('-inf')
        for i in range(n-2, -1, -1):
            if nums[i] < max_k:
                return True
            while priority_stack and priority_stack[-1] < nums[i]:
                max_k = priority_stack.pop()
            priority_stack.append(nums[i])
        return False




