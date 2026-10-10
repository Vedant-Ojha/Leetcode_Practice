class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 2:
            return max(nums)
        def solve(nums):
            n = len(nums)
            dp = [0] * n
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])

            for i in range(2,n):
                dp[i] = max(dp[i-1], nums[i] + dp[i-2])
            return dp[-1]
        c1 = solve(nums[:-1])        
        c2 = solve(nums[1:])
        return max(c1,c2)