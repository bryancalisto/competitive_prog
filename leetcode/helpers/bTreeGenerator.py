class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def generateBTree(data):
    if data == None or len(data) == 0:
        return None

    nodeQueue = []
    intQueue = []

    for i in range(1, len(data)):
        intQueue.append(data[i])

    node = TreeNode(data[0])
    nodeQueue.append(node)

    while intQueue:
        leftVal = intQueue.pop(0)
        rightVal = intQueue.pop(0)

        currentNode = nodeQueue.pop(0)

        left = TreeNode(leftVal)
        currentNode.left = left
        nodeQueue.append(left)

        right = TreeNode(rightVal)
        currentNode.right = right
        nodeQueue.append(right)

    return node


# tree = creatBTree([1, 2, 2, 3, None, 1, 3, 4, 8, 1, 4])

# print(tree.val)
# print(tree.left.right.val)
# print(tree.right.val)
