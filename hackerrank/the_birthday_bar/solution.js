//https://www.hackerrank.com/challenges/the-birthday-bar/

function birthday(s, d, m) {
  let count = 0;

  for (let i = 0; i < s.length; i++) {
    let sum = 0;

    for (let j = 0; j < m && j + i < s.length; j++) {
      sum += s[j + i];
    }

    if (sum === d) {
      count++;
    }
  }

  return count;
}

console.log(birthday([1, 2, 1, 3, 2], 3, 2));