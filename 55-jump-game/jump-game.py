class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_reach = 0
        n = len(nums)
        for i, jump in enumerate(nums):
            # if this index is not even reachable, we fail immediately
            if i > max_reach:
                return False
            # otherwise update how far we can reach from here
            max_reach = max(max_reach, i + jump)
            # early exit: once we can reach or pass the last index
            if max_reach >= n - 1:
                return True
        
        return False
