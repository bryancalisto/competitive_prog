//https://www.hackerrank.com/challenges/utopian-tree/problem
function utopianTree(n) {
  let height = 0

  for (let i = 0; i < n + 1; i++) {
    if (i % 2 === 0) height += 1
    else height *= 2
  }

  return height
}

for (let i = 0; i < 10; i++) {
  console.log(utopianTree(i));
}