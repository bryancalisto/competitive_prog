# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    res = []

    def helper(self, root: Optional[TreeNode]):
        if root == None:
            return

        self.helper(root.left)
        self.res.append(root.val)
        self.helper(root.right)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.helper(root)
        return self.res


root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(Solution().postorderTraversal(root))
