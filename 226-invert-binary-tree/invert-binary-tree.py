# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        cur = root
        bfs = deque([root])
        while bfs:
            node = bfs.popleft()
            node.left, node.right = node.right, node.left
            if node.left: 
                bfs.append(node.left)
            if node.right:
                bfs.append(node.right)
                
        return cur
        