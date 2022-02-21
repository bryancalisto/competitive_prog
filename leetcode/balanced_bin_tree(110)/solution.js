const generateBTree = require('../helpers/bTreeGenerator');

var isBalanced = function (root) {
  return helper(root).isBalanced;
};

var helper = function (root) {
  if (!root) return { isBalanced: true, height: 0 };
  const left = helper(root.left);
  const right = helper(root.right);

  return {
    isBalanced: left.isBalanced && right.isBalanced && Math.abs(left.height - right.height) <= 1,
    height: 1 + Math.max(left.height, right.height)
  };
};


// const root = generateBTree([1, 2, 2, 3, null, null, 3, 4, null, null, 4]);
const root = generateBTree([1, 2, 2, 3, 3, null, null, 4, 4]);
console.log(isBalanced(root));