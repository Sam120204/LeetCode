# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def ifsym(self, arr: List[TreeNode]) -> bool:
        print("here")
        for i in range(len(arr)//2):
            if arr[i].val != arr[len(arr)-i-1].val:
                return False
        return True

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])
        while q:
            size = len(q)
            if not self.ifsym(q):
                return False
            for i in range(size):
                cur = q.popleft()
                if cur.val != 101:
                    if cur.left:
                        q.append(cur.left)
                    else:
                        q.append(TreeNode(101))
                    if cur.right:
                        q.append(cur.right)
                    else:
                        q.append(TreeNode(101))
        return True

        