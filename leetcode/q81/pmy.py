class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        index = 1
        while index < n:
            if nums[index] < nums[index-1]:
                break
            index += 1

        left = 0
        right = index - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        left = index
        right = n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False

