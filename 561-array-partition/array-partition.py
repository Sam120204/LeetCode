class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        # sum of mins of pairs (nums[0],nums[1]), (nums[2],nums[3]), ...
        return sum(nums[::2])
