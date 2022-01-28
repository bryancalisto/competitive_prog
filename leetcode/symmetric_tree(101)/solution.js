function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

var helper = function (left, right) {
  if (!left && !right) return true

  if (left.val !== right.val || (!left && right) || (!right && left)) return false

  const res1 = helper(left.left, right.right);
  const res2 = helper(left.right, right.left);

  if (res1 === false || res2 === false) {
    return false
  }

  return
};

var isSymmetric = function (root) {
  return helper(root.left, root.right)
};

const root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
// const root = new TreeNode(1, new TreeNode(2, null, new TreeNode(3)), new TreeNode(2, null, new TreeNode(3)));
console.log(isSymmetric(root));