# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        currentNode = root

        while currentNode:
            if currentNode.val > p.val and currentNode.val > q.val:
                currentNode = currentNode.left
            elif currentNode.val < p.val and currentNode.val < q.val:
                currentNode = currentNode.right
            else:
                return currentNode


node = TreeNode(6)

node.left = TreeNode(2)
node.right = TreeNode(8)

node.left.left = TreeNode(0)
node.left.right = TreeNode(4)

node.right.left = TreeNode(7)
node.right.right = TreeNode(9)

print(Solution().lowestCommonAncestor(node, TreeNode(2), TreeNode(4)).val)
