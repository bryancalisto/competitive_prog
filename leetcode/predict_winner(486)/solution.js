function _PredictTheWinner(nums, start, end, A, B, turn) {
  if (start > end) {
    return A >= B
  }

  if (turn === 1) { // play player 1 turn (prepare player 2's turn environment)
    // Player can decibe between nums[0] OR nums[nums.length - 1]
    return _PredictTheWinner(nums, start + 1, end, A + nums[start], B, 2) || _PredictTheWinner(nums, start, end - 1, A + nums[end], B, 2)
  }
  else { // play player 2 turn (prepare player 1's turn environment)
    // If was predicted that player 1 would win in ways nums[0] AND nums[nums.length-1], then player 1 will win
    return _PredictTheWinner(nums, start + 1, end, A, B + nums[start], 1) && _PredictTheWinner(nums, start, end - 1, A, B + nums[end], 1)
  }

}

function PredictTheWinner(nums) {
  return _PredictTheWinner(nums, 0, nums.length - 1, 0, 0, 1);
}

console.log(PredictTheWinner([1, 1, 1])) // true
console.log(PredictTheWinner([1, 5, 2])) // false
console.log(PredictTheWinner([1, 5, 233, 7])) // true