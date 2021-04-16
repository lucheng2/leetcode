n = int(input().strip())
nums = list(map(int, input().strip().split()))
target = int(input().strip())
ans = -1
for i in range(len(nums)):
    if nums[i] == target:
        ans = i + 1
        break
print(ans)
