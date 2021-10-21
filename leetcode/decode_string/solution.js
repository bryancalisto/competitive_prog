var decodeString = function (s) {
  if (!/\d/.test(s)) {
    return s
  }

  let tmpStr = ''

  for (let i = 0; i < s.length; i++) {
    if (/\d/.test(s[i])) {
      let num = ''
      while (/\d/.test(s[i])) {
        num += s[i]
        i++
      }

      let openingBracketIndex = i + 1
      let closingBracketIndex = openingBracketIndex
      let openBrackets = 1

      while (openBrackets !== 0) {
        closingBracketIndex++

        if (s[closingBracketIndex] === '[') {
          openBrackets++
        }

        if (s[closingBracketIndex] === ']') {
          openBrackets--
        }
      }

      i = closingBracketIndex

      // console.log(s.slice(openingBracketIndex, closingBracketIndex));
      let solveInner = decodeString(s.slice(openingBracketIndex, closingBracketIndex))

      // console.log(solveInner);
      for (let j = 0; j < Number(num); j++) {
        tmpStr += solveInner
      }

    }
    else {
      // console.log('else: ', s[i]);
      tmpStr += s[i]
    }
  }

  return tmpStr
};

// console.log(decodeString('abcdef')); // abcdef
// console.log(decodeString('3[a2[c]]')); // accaccacc
// console.log(decodeString('2[abc]3[cd]ef')); // abcabccdcdcdef
console.log(decodeString('abc3[cd]xyz')); // abccdcdcdxyz