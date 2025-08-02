# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0

        lst = []
        q = deque([root])

        while q:
            current_size = len(q)
            for i in range(current_size):
                node = q.popleft()
                lst.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        
        lst.sort()
        min_diff = float('inf')
        for i in range(1, len(lst)):
            min_diff = min(min_diff, lst[i] - lst[i-1])
        
        return min_diff
            
        