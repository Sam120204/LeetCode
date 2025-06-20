import heapq
from collections import Counter

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Step 1: Count frequency
        freq = Counter(nums)  # O(n)
        
        print(freq)
        # Step 2: Build a min-heap of size k
        min_heap = []  # (frequency, number)
        
        for num, count in freq.items():
            heapq.heappush(min_heap, (count, num))  # O(log k)
            if len(min_heap) > k:
                heapq.heappop(min_heap)  # maintain size k
        
        # Step 3: Extract elements from heap
        return [num for count, num in min_heap]
