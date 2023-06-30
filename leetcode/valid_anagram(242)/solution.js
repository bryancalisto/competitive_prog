var isAnagram = function (s, t) {
  const mem = {};

  if (s.length !== t.length) return false;

  for (let i = 0; i < s.length; i++) {
    if (!(s[i] in mem)) {
      mem[s[i]] = 0;
    }

    if (!(t[i] in mem)) {
      mem[t[i]] = 0;
    }

    mem[s[i]]++;
    mem[t[i]]--;
  }

  return Object.values(mem).every(v => v === 0);
};

console.log(isAnagram('anagram', 'nagaram'))