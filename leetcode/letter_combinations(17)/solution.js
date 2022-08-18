var letterCombinations = function (digits) {
  let res = [];

  if (!digits) return res;

  const digitsToLetters = [
    [],
    [],
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
    ['m', 'n', 'o'],
    ['p', 'q', 'r', 's'],
    ['t', 'u', 'v'],
    ['w', 'x', 'y', 'z'],
  ];

  res.push('');

  for (let digit of digits) {
    const newRes = [];

    for (let comb of res) {
      for (let char of digitsToLetters[Number(digit)]) {
        const newComb = comb + char;
        newRes.push(newComb);
      }
    }

    res = newRes;
  }

  return res;
};

console.log(letterCombinations('234'));