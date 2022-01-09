//https://www.hackerrank.com/challenges/the-birthday-bar/

function birthday(s, d, m) {
  let count = 0;
  let prevStart = 0;
  let sum = 0;

  for (let i = 0; i < m; i++) {
    sum += s[i];
  }

  if (sum === d) {
    count++;
  }

  for (let i = m; i < s.length; i++) {
    sum += s[i] - s[prevStart];
    if (sum === d) {
      count++;
    }
    prevStart++
  }

  return count;
}

console.log(birthday([1, 2, 1, 3, 2], 3, 2));