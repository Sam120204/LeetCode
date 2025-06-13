# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type headA: ListNode
        :type headB: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None

        p1 = headA
        p2 = headB

        # When either pointer hits the end, switch it to the other list's head
        while p1 != p2:
            p1 = p1.next if p1 else headB
            p2 = p2.next if p2 else headA

        return p1  # This is the intersection node or None

        