class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        dp = [0 for i in range(len(nums))]
        for i in range(2,len(nums)):
            if nums[i-1] * 2 == nums[i-2] + nums[i]:
                dp[i] = dp[i-1] + 1
        print(dp)
        return sum(dp)