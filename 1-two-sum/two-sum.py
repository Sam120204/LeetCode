class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_index={}
        for i in range(len(nums)):
            if nums[i] not in nums_index:
                nums_index[nums[i]] = [i]
            else:
                nums_index[nums[i]].append(i)

        nums.sort()
        left, right = 0, len(nums)-1
        while left <= right:
            if nums[left] + nums[right] == target:
                if nums[left] == nums[right]:
                    return [nums_index[nums[left]][0], nums_index[nums[left]][1]]
                else:
                    return [nums_index[nums[left]][0], nums_index[nums[right]][0]]
            elif nums[left] + nums[right] > target:
                right-=1
            else: left+=1
        return [-1,-1]
            
                
        