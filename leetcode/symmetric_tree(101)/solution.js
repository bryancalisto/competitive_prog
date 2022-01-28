function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

var helper = function (left, right) {
  if (!left && !right) return true

  if (!(left && right)) return false

  return left.val === right.val && helper(left.left, right.right) && helper(left.right, right.left);
};

var isSymmetric = function (root) {
  return helper(root.left, root.right)
};

// const root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
const root = new TreeNode(1, new TreeNode(2, null, new TreeNode(3)), new TreeNode(2, null, new TreeNode(3)));
console.log(isSymmetric(root));