class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        left = 0
        curr = 0
        best = float('inf')  # acts like +INF

        for right in range(n):
            curr += nums[right]

            # shrink from the left while we still meet/exceed target
            while curr >= target:
                best = min(best, right - left + 1)
                curr -= nums[left]
                left += 1

        return 0 if best == float('inf') else best
