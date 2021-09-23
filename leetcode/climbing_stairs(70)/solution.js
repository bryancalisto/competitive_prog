var climbStairs = function (n) {
  var _climbStairs = function (i, n, mem = {}) {
    let count = 0

    if (i in mem) return mem[i]

    if (i >= n) {
      return 1
    }

    count += _climbStairs(i + 1, n, mem) + _climbStairs(i + 2, n, mem)

    mem[i] = count
    return count
  }

  return _climbStairs(0, n - 1)
};

console.log(climbStairs(4)) // 5
console.log(climbStairs(44)) // 1134903170