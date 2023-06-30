var convertToTitle = function (columnNumber) {
  let result = '';

  while (columnNumber) {
    const newChar = 65 + Math.trunc((columnNumber - 1) % 26);
    columnNumber = Math.trunc((columnNumber - 1) / 26);
    result = String.fromCharCode(newChar) + result;
  }

  return result;
};

console.log(convertToTitle(701));