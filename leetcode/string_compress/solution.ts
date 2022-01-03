function compress(chars: string): string {
  let res = '';
  let currentChar = chars[0];
  let count = 1;

  for (let i = 1; i < chars.length; i++) {
    if (currentChar === chars[i]) {
      count++;
      continue;
    }

    res += `${count}${currentChar}`;
    currentChar = chars[i];
    count = 1;
  }

  res += `${count}${currentChar}`;

  return res;
};

console.log(compress('ab'));

