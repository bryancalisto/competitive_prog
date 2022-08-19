var topKFrequent = function (nums, k) {
  const tbl = {}

  for (const num of nums) {
    if (!tbl[num]) {
      tbl[num] = 0
    }

    tbl[num]++
  }

  const vals = Object.entries(tbl).sort((a, b) => b[1] - a[1]).splice(0, k).map(entry => entry[0])

  return vals
};

console.log(topKFrequent([1, 1, 1, 2, 2, 3, 7, 7, 7], 2));