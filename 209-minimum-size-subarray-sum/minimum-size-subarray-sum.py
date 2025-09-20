class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        left = 0
        cur_sum = 0
        min_len = float('inf')

        for right in range(n):
            cur_sum += nums[right]

            # shrink from the left while we subarray sum >= target
            while cur_sum >= target:
                min_len = min(min_len, right - left + 1)
                cur_sum -= nums[left]
                left += 1

        if min_len == float('inf'):
            return 0
        else:
            return min_len
        