class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        window = sum(nums[:k])
        best = window

        for i in range(k, len(nums)):
            window += nums[i] - nums[i-k]
            best = max(best, window)

        return best/float(k)
