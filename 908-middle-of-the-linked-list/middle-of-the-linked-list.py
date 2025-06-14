# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def middleNode(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Step 1: Count total number of nodes
        count = 0
        current = head
        while current:
            count += 1
            current = current.next

        # Step 2: Go to the middle node
        middle_index = count // 2
        current = head
        for _ in range(middle_index):
            current = current.next
        
        return current
