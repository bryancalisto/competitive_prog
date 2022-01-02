function subsetXORSum(nums: number[]): number {
  let sum = 0;
  let combs: number[][] = [[]];

  for (let num of nums) {
    let newCombs: number[][] = [];

    for (let comb of combs) {
      newCombs.push([...comb, num]);
    }

    combs = [...combs, ...newCombs];
  }

  combs.forEach(comb => {
    let newNum = comb.reduce((a, b) => a ^ b, 0);
    console.log(newNum);
    sum += newNum;
  });

  return sum;
};

let nums = [1, 3];
nums = [5, 1, 6];
console.log(subsetXORSum(nums));