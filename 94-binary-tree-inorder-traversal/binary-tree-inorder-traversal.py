# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        res = []

        def DFS(node):
            if not node:
                return
            DFS(node.left)
            res.append(node.val)
            DFS(node.right)
        
        DFS(root)

        return res