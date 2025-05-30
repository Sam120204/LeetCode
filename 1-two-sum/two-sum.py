# class Solution(object):
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         num_to_index = {}
#         for i, num in enumerate(nums):
#             complement = target - num
#             if complement in num_to_index:
#                 return [num_to_index[complement], i]
#             num_to_index[num] = i
#         return []
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Keep track of original indices
        nums_with_index = [(num, i) for i, num in enumerate(nums)]
        # Sort based on the number values
        nums_with_index.sort()

        lo, hi = 0, len(nums_with_index) - 1
        while lo < hi:
            num_lo, idx_lo = nums_with_index[lo]
            num_hi, idx_hi = nums_with_index[hi]
            current_sum = num_lo + num_hi
            if current_sum < target:
                lo += 1
            elif current_sum > target:
                hi -= 1
            else:
                return [idx_lo, idx_hi]
        return []
