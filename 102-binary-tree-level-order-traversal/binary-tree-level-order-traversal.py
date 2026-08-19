# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = deque([root])
        res = []
        while q:
            res.append([i.val for i in q])
            size = len(q)
            for i in range(size):
                cur = q.popleft()
                if (cur.left):
                    q.append(cur.left)
                if (cur.right):
                    q.append(cur.right)


        return res