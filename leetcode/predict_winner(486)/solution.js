function _PredictTheWinner(nums, start, end, A, B, turn) {
  if (start > end) {
    console.log(`FINAL 1:  sumA ${A} sumB ${B}`);
    return A >= B
  }
  else if (start == end) {
    if (turn == 1) {
      console.log(`FINAL 2: nums ${nums.slice(start, end + 1)},  sumA ${A + nums[start]}, sumB ${B}`);
      return (A + nums[start]) >= B
    }
    else {
      console.log(`FINAL 3: nums ${nums.slice(start, end + 1)},  sumA ${A}, sumB ${B + nums[start]}`);
      return A < (B + nums[start])
    }
  }
  else {
    if (turn == 1) {
      console.log(`A: turn ${turn},nums ${nums.slice(start, end + 1)},  sumA ${A}, sumB ${B}`);
      return !(_PredictTheWinner(nums, start + 1, end, A + nums[start], B, 2) &&
        _PredictTheWinner(nums, start, end - 1, A + nums[end], B, 2))
    }
    else {
      console.log(`B: turn ${turn}, nums ${nums.slice(start, end + 1)}, sumA ${A}, sumB ${B}`);
      return !(_PredictTheWinner(nums, start + 1, end, A, B + nums[start], 1)
        && _PredictTheWinner(nums, start, end - 1, A, B + nums[end], 1))
    }
  }
}

function PredictTheWinner(nums) {
  return _PredictTheWinner(nums, 0, nums.length - 1, 0, 0, 1);
}

// console.log(PredictTheWinner([1, 1, 1])) // true
console.log(PredictTheWinner([1, 5, 2])) // false
// console.log(PredictTheWinner([1, 5, 233, 7])) // true