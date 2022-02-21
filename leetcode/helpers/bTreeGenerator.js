function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

const generateBTree = (arr) => {
  if (!arr) return null;

  const valQueue = [];
  const nodeQueue = [];

  for (const val of arr) {
    valQueue.push(val);
  }

  const node = new TreeNode(valQueue.shift());
  nodeQueue.push(node);

  while (valQueue.length > 0) {
    const currentNode = nodeQueue.shift();

    let currentVal = valQueue.shift();
    if (currentVal) {
      left = new TreeNode(currentVal);
      currentNode.left = left;
      nodeQueue.push(left);
    }

    currentVal = valQueue.shift();
    if (currentVal) {
      right = new TreeNode(currentVal);
      currentNode.right = right;
      nodeQueue.push(right);
    }
  }

  return node;
}

// const root = generateBTree([1, 2, 2, 3, null, null, 3, 4, null, null, 4]);
// console.log(root.val);
// console.log(root.left.val);
// console.log(root.right.val);
// console.log(root.left.left.val);

module.exports = generateBTree;