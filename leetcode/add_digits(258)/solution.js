var addDigits = function (num) {
  while (num > 9) {
    let currNum = num;
    let sum = 0;

    while (currNum > 0) {
      sum += currNum % 10;
      currNum = Math.trunc(currNum / 10);
    }

    num = sum;
  }

  return num;
};

console.log(addDigits(38));