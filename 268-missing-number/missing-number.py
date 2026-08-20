class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        total = 0
        for i in range(n):
            total += nums[i]
        ex_sum = n*(n+1) // 2
        return ex_sum - total


        
                