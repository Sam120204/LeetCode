class Solution(object):
    def largestSumAfterKNegations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # 1) Process larger |value| first; smallest |value| ends last
        nums.sort(key=abs, reverse=True)

        # 2) Flip negatives while we have k
        for i in range(len(nums)):
            if nums[i] < 0 and k > 0:
                nums[i] = -nums[i]
                k -= 1

        # 3) If k is still odd, flip the smallest |value| once
        if k % 2 == 1:
            nums[-1] = -nums[-1]

        return sum(nums)
