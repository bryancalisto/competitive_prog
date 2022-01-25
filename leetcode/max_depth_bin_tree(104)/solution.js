/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

var helper = function (root, max, count) {
  if (!root) return count

  let currentCount = helper(root.left, max, count + 1)

  if (currentCount > max) {
    max = currentCount
  }

  currentCount = helper(root.right, max, count + 1)

  if (currentCount > max) {
    max = currentCount
  }

  return max
};

var maxDepth = function (root) {
  return helper(root, 0, 0)
};

const root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
console.log(maxDepth(root));