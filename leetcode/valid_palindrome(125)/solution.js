var isPalindrome = function (s) {
  const stack = [];
  const queue = [];
  let i = 0;
  let j = s.length - 1;

  while (i <= j) {
    const char0 = s[i].toLowerCase();

    if (!/[a-z0-9]/i.test(char0)) {
      i++;
      continue;
    }

    const char1 = s[j].toLowerCase();
    if (!/[a-z0-9]/i.test(char1)) {
      j--;
      continue;
    }

    console.log(char0, char1);
    if (char0 !== char1) {
      return false;
    }

    i++;
    j--;
  }

  return true;
};

console.log(isPalindrome('A man, a plan, a canal: Panama')); // true