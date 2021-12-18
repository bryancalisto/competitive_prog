# Definition for a binary tree node.
from typing import Dict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root: TreeNode, k: int, table) -> bool:
        print(f'val: {root.val}, {table}')
        rest = k - root.val

        if root.val in table:
            return True

        if rest not in table:
            table[rest] = 1

        if root.left:
            if self.helper(root.left, k, table):
                return True

        if root.right:
            if self.helper(root.right, k, table):
                return True

        return False

    def findTarget(self, root: TreeNode, k: int) -> bool:
        return self.helper(root, k, {})


root = TreeNode(5, TreeNode(3), TreeNode(4))
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.right.left = None
root.right.right = TreeNode(7)
root = TreeNode(1)
# k = 28
k = 2
sol = Solution()
print(sol.findTarget(root, k))
