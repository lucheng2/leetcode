from typing import List


class Status:
    def __init__(self, iSum, lSum, rSum, mSum):
        self.iSum = iSum
        self.lSum = lSum
        self.rSum = rSum
        self.mSum = mSum


def pushUp(left: Status, right: Status) -> Status:
    iSum = left.iSum + right.iSum
    lSum = max(left.lSum, left.iSum + right.lSum)
    rSum = max(right.rSum, right.iSum + left.rSum)
    mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum)
    return Status(iSum, lSum, rSum, mSum)


def get(nums: List[int], left: int, right: int) -> Status:
    if left == right:
        return Status(nums[left], nums[left], nums[left], nums[left])
    mid = (right - left) // 2 + left
    ls = get(nums, left, mid)
    rs = get(nums, mid + 1, right)
    return pushUp(ls, rs)


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = get(nums, 0, len(nums) - 1)
        return s.mSum


if __name__ == '__main__':
    s = Solution()
    a = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    ans = s.maxSubArray(a)
    print(ans)
