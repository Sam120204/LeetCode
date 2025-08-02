# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if not root:
            return 0

        q = deque([root])

        while q:
            current_size = len(q)
            level = []
            for i in range(current_size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    level.append(node.left.val)
                else:
                    level.append(101)

                    
                if node.right:
                    q.append(node.right)
                    level.append(node.right.val)
                else:
                    level.append(101)
                
            # level = [3, 4, 4, 3]
            # here to check if it is mirror
            if level != level[::-1]:
                return False

        return True
