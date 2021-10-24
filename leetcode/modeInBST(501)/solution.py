# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    prev = None
    count = 1
    mode = 0
    modes = []

    def helper(self, node: TreeNode):
        if not node:
            return

        self.helper(node.left)

        if self.prev and self.prev.val == node.val:
            self.count += 1
        else:
            self.count = 1

        if self.count > self.mode:
            self.mode = self.count
            self.modes.clear()
            self.modes.append(node.val)
        elif self.count == self.mode:
            self.modes.append(node.val)

        self.prev = node

        self.helper(node.right)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.helper(root)
        return self.modes


node = TreeNode(8)

node.left = TreeNode(4)
node.right = TreeNode(9)

node.left.left = TreeNode(3)
node.left.right = TreeNode(5)

node.right.left = TreeNode(8)
node.right.right = TreeNode(11)

print(Solution().findMode(node))
