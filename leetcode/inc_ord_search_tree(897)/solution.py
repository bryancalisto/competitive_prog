# https://leetcode.com/problems/increasing-order-search-tree/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    newRoot: TreeNode = None

    def helper(self, root: TreeNode) -> TreeNode:
        if root.left:
            self.increasingBST(root.left)

        if not self.newRoot:
            self.newRoot = TreeNode(root.val)
        else:
            tmp = self.newRoot
            while tmp.right:
                tmp = tmp.right
            tmp.right = TreeNode(root.val)

        if root.right:
            self.increasingBST(root.right)

    def increasingBST(self, root: TreeNode) -> TreeNode:
        self.helper(root)
        return self.newRoot


data = [5, 3, 6, 2, 4, None, 8, 1, None, None, None, 7, 9]

# root = TreeNode(5,
#                 TreeNode(3,
#                          TreeNode(2,
#                                   TreeNode(1), None
#                                   ),
#                          TreeNode(4)
#                          ),
#                 TreeNode(6,
#                          None, TreeNode(8,
#                                         TreeNode(7), TreeNode(9)
#                                         )
#                          )
#                 )

root = TreeNode(5, TreeNode(1), TreeNode(5))  # 1 5 5
root.left.left = TreeNode(2)
root.left.right = TreeNode(7)
root.right.left = TreeNode(20)
root.right.right = TreeNode(70)
# 2 1 7 5 20 5 70
sol = Solution()
sol.increasingBST(root)
print(sol.newRoot.val)
print(sol.newRoot.right.val)
print(sol.newRoot.right.right.val)
print(sol.newRoot.right.right.right.val)
print(sol.newRoot.right.right.right.right.val)
print(sol.newRoot.right.right.right.right.right.val)
print(sol.newRoot.right.right.right.right.right.right.val)
