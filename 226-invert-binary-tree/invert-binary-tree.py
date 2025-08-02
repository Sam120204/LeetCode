# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return None

        q = deque([root])

        while q:
            current_size = len(q)
            for i in range(current_size):
                node = q.popleft()

                node.left, node.right = node.right, node.left

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

        return root
