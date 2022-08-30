var combinationSum2 = function (candidates, target) {
  let res = []
  candidates.sort((a, b) => a - b)

  const backtrack = (start, comb, target) => {
    if (target === 0) {
      res.push([...comb])
      return
    }

    if (target < 0) {
      return
    }

    let prev = -1
    let newComb = [...comb]

    for (let i = start; i < candidates.length; i++) {
      if (candidates[i] === prev) {
        continue
      }

      newComb.push(candidates[i])
      backtrack(i + 1, newComb, target - candidates[i])
      newComb.pop()
      prev = candidates[i]
    }
  }

  backtrack(0, [], target)

  return res
}


console.log(combinationSum2([10, 1, 2, 7, 6, 1, 5], 8));