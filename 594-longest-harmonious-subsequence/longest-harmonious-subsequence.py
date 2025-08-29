class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        left = 0
        best = 0

        for right in range(len(nums)):
            # shrink window until max - min <= 1
            while nums[right] - nums[left] > 1:
                left += 1

            # record only when max - min == 1 (harmonious)
            if nums[right] - nums[left] == 1:
                best = max(best, right - left + 1)

        return best
