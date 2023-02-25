function isPalindrome(s, start, end) {
  while (start < end) {
    console.log(`... ${s[start]} === ${s[end]}`);
    if (s[start] !== s[end]) {
      return false;
    }

    start++;
    end--;
  }

  return true;
}

function palindromeIndex(s) {
  let index = -1;
  let start = 0;
  let end = s.length - 1;

  while (start < end) {
    if (s[start] !== s[end]) {
      console.log(`${s[start]} === ${s[end]}`);

      if (isPalindrome(s, start + 1, end)) {
        index = start;
      } else if (isPalindrome(s, start, end - 1)) {
        index = end;
      }

      break;
    }

    start++;
    end--;
  }

  return index;
}

console.log(palindromeIndex('aaab'));
console.log(palindromeIndex('baa'));
console.log(palindromeIndex('aaa'));