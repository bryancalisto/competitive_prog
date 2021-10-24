# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    minimum = 1000000000
    prev: TreeNode = None

    def helper(self, node: TreeNode) -> int:
        if not node:
            return

        self.helper(node.left)

        if self.prev:
            diff = abs(self.prev.val - node.val)

            if diff < self.minimum:
                self.minimum = diff

        self.prev = node

        self.helper(node.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.helper(root)
        return self.minimum


# node = TreeNode(5)

# node.left = TreeNode(4)
# node.right = TreeNode(7)
######

# node = TreeNode(1)

# node.left = TreeNode(0)
# node.right = TreeNode(48)

# node.right.left = TreeNode(12)
# node.right.right = TreeNode(49)
######

node = TreeNode(236)

node.left = TreeNode(104)
node.right = TreeNode(701)

node.left.right = TreeNode(227)
node.right.right = TreeNode(911)

print(Solution().getMinimumDifference(node))
