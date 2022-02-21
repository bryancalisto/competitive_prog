const generateBTree = require('../helpers/bTreeGenerator');

function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

let minim = 1000;

var helper = function (root, count) {
  if (!root) return;
  if (!root.left && !root.right) {
    minim = Math.min(minim, count);
  }

  helper(root.left, count + 1);
  helper(root.right, count + 1);
};

var minDepth = function (root) {
  helper(root, 1);
  return minim;
};

const root = generateBTree([3, 9, 20, null, null, 15, 7]);
// const root = generateBTree([2, null, 3, null, 4, null, 5, null, 6]);
console.log(minDepth(root));