//https://leetcode.com/problems/minimum-path-sum/
/**
 * @param {number[][]} grid
 * @return {number}
 */

var minPathSum = function (grid) {
  const m = grid.length
  const n = grid[0].length

  for (let i = 1; i < m; i++) {
    grid[i][0] = grid[i - 1][0] + grid[i][0]
  }

  for (let i = 1; i < n; i++) {
    grid[0][i] = grid[0][i - 1] + grid[0][i]
  }

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1])
    }
  }

  return grid[m - 1][n - 1]
};

console.log(minPathSum([[0]]))
console.log(minPathSum([[1, 2, 3], [4, 5, 6]]))
console.log(minPathSum([[1, 3, 1], [1, 5, 1], [4, 2, 1]]))