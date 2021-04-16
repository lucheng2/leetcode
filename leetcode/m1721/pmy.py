class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l_high = [0] * n
        r_high = [0] * n
        l_max = height[0]
        for i in range(0, n):
            l_max = max(l_max, height[i])
            l_high[i] = l_max
        r_max = height[n-1]
        for i in range(n-1, -1, -1):
            r_max = max(r_max, height[i])
            r_high[i] = r_max
        water = [0] * n
        for i in range(0, n):
            water = min(l_high[i], r_high[i]) - height[i]
        ans = sum(water)
        return int(ans)

