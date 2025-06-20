import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Build a min-heap of the first k elements
        heap = nums[:k]
        heapq.heapify(heap)  # O(k)

        # Process the remaining elements
        for num in nums[k:]:
            if num > heap[0]:  # If larger than smallest in heap
                heapq.heappop(heap)
                heapq.heappush(heap, num)

        # The root is the kth largest
        return heap[0]
