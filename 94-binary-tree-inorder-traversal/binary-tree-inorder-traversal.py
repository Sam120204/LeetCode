# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode], lst) -> None:
        if not root:
            return None
        self.dfs(root.left, lst)
        lst.append(root.val)
        self.dfs(root.right, lst)
        

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        lst = []
        self.dfs(root, lst)
        return lst
