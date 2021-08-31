/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
  const result = []
  let popped

  if (nums.length === 1) return [[...nums]]

  for (let i = 0; i < nums.length; i++) {
    popped = nums[0]
    nums = nums.slice(1)
    let newPerms = permute(nums)
    result.push(...newPerms.map(p => [...p, popped]))
    nums.push(popped)
  }

  return result
};

console.log(permute([1, 2, 3]));