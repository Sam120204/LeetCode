class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = {}
        for i in range(len(nums)):
            if (nums[i] in count):
                count[nums[i]] += 1
            else:
                count[nums[i]] = 1

        best = 0
        for key in count:
            if key+1 in count:
                best = max(best, count[key] + count[key+1])
        return best