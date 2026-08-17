class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []

        while head:
            stack.append(head.val)
            head = head.next

        dummy = ListNode()
        cur = dummy

        while stack:
            cur.next = ListNode(stack.pop())
            cur = cur.next

        return dummy.next