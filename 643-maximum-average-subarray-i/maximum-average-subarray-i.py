class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # sum of the first window
        window = sum(nums[:k])
        best = window

        # slide the window across the array
        for i in range(k, len(nums)):
            window += nums[i] - nums[i - k]
            if window > best:
                best = window

        return best / float(k)
