class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = 0
        for i in nums:
            if i == 0:
                count+=1
        for i in range(count):
            nums.remove(0)
        for i in range(count):
            nums.append(0)