var titleToNumber = function (columnTitle) {
  let col = 0;
  let len = columnTitle.length - 1;

  for (char of columnTitle) {
    const charNumber = char.charCodeAt(0) - 64;
    col += charNumber * (26 ** len--);
  }

  return col;
};

console.log(titleToNumber('ZYZ'));