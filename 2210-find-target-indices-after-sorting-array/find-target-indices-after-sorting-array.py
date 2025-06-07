class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums.sort()
        # new_nums = sorted(nums) -> copy not in place

        # helper functions:
        # benefits: 1. code clean + neat; 2. clear logic 3. each function does their own things
        # first index of the target
        def find_first():
            left, right = 0, len(nums)-1
            res = -1
            # perform bianry search
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] < target:
                    left = mid + 1
                else: # nums[mid] >= target:
                    if nums[mid] == target:
                        res = mid
                    right = mid -1
            return res

        # find last index of the target
        def find_last():
            left, right = 0, len(nums)-1
            res = -1
            # perform bianry search
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] > target:
                    right = mid - 1
                else: # nums[mid] <= target:
                    if nums[mid] == target:
                        res = mid
                    left = mid + 1
            return res

        first = find_first()
        last = find_last()

        # theres chance that no target exists in the array
        if (first == -1) or (last == -1):
            return []

        return list(range(first, last+1))


        
