var lengthOfLIS = function (nums) {
  let tbl = Array.from({ length: nums.length }).fill(1)
  let res = 1;

  for (let i = 1; i < nums.length; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        tbl[i] = Math.max(tbl[j] + 1, tbl[i])
        if (tbl[i] > res) {
          res = tbl[i]
        }
      }
    }
  }

  return res
};


// const input = [0, 1, 0, 3, 2, 3];
const input = [1, 3, 6, 7, 9, 4, 10, 5, 6];

console.log(lengthOfLIS(input));