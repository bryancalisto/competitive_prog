from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def helper(self, root: 'Node', res: List[int]) -> List[int]:
        if not root:
            return res

        res.append(root.val)

        if root.children:
            for node in root.children:
                res = self.helper(node, res)

        return res

    def preorder(self, root: 'Node') -> List[int]:
        return self.helper(root, [])


root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])  # [1, 3, 5, 6, 2, 4]

print(Solution().preorder(root))
