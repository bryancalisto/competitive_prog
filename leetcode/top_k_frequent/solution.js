var topKFrequent = function (nums, k) {
  const frequency = Array.from({ length: nums.length + 1 }, () => [])
  const counters = {}

  for (const num of nums) {
    counters[num] = 1 + (counters[num] ?? 0)
  }

  for (const key in counters) {
    frequency[counters[key]].push(key)
  }

  const res = []

  for (let i = frequency.length - 1; i > 0; i--) {
    for (const num of frequency[i]) {
      res.push(num)
      if (res.length === k) return res
    }
  }
};

console.log(topKFrequent([1, 1, 1, 2, 2, 3, 7, 7, 7], 2));