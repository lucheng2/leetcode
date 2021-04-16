n = int(input().strip())
nums = list(map(int, input().strip().split()))
nums = sorted(nums)
# print(' '.join(map(str, nums)))
for i in range(n):
    print(nums[i], end=' ')
