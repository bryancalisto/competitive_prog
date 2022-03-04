var isPalindrome = function (s) {
  const stack = [];
  const queue = [];
  let char;

  for (let i = 0; i < s.length; i++) {
    char = s[i].toLowerCase();
    if (/[a-z0-9]/i.test(char)) {
      queue.push(char);
    }
  }

  for (let i = 0; i < s.length; i++) {
    char = s[i].toLowerCase();
    if (/[a-z0-9]/i.test(char)) {
      let comparing = queue.pop();
      if (comparing !== char) {
        return false;
      }
    }
  }

  return true;
};

console.log(isPalindrome('A man, a plan, a canal: Panama')); // true