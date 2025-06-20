# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        heap = []

        # Initialize the heap with the head node of each list
        for i, node in enumerate(lists):
            if node:
                # Push a tuple (node value, unique index, node)
                heapq.heappush(heap, (node.val, i, node))

        dummy = ListNode(-1)
        p = dummy

        # Pop the smallest node and push its next to the heap
        while heap:
            val, i, node = heapq.heappop(heap)
            p.next = node
            p = p.next
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))

        return dummy.next
