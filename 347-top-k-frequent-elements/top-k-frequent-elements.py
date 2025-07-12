import heapq
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # count freq
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        # freq = {1:3, 2:2, 3:1}
        # how to use heap? 
        # using min-heap of size k
        heap = []
        for key in freq:
            val = freq[key]
            heapq.heappush(heap, (val, key))
            if len(heap) > k:
                heapq.heappop(heap)

        # from here, heap only contains top k elements
        # res = []
        # for (key, val) in heap:
        #     res.append(val)

        res = [val for (key, val) in heap]
        return res


        