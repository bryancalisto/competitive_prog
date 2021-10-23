# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def _sortedArrayToBST(self, left, right, nums):
        if left > right:
            return None

        med = (left + right) // 2
        node = TreeNode(nums[med])
        node.left = self._sortedArrayToBST(left, med - 1, nums)
        node.right = self._sortedArrayToBST(med + 1, right, nums)

        return node

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self._sortedArrayToBST(0, len(nums) - 1, nums)


sol = Solution()
print(str(sol.sortedArrayToBST([-10, -3, 0, 5, 9])))
