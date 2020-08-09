/*
---Recursion 101---
In this Kata, you will be given two positive integers a and b and your task will be to apply the following operations:

i) If a = 0 or b = 0, return [a,b]. Otherwise, go to step (ii);
ii) If a ≥ 2*b, set a = a - 2*b, and repeat step (i). Otherwise, go to step (iii);
iii) If b ≥ 2*a, set b = b - 2*a, and repeat step (i). Otherwise, return [a,b].
*/

function solve(a, b) {
  for (;;) {
    if (a === 0 || b === 0) {
      return [a, b];
    } else if (a >= 2 * b) {
      const divisionA =
        Math.floor(a / b) % 2 === 0 ? Math.floor(a / b) : Math.floor(a / b) - 1;
      a -= divisionA * b;
    } else if (b >= 2 * a) {
      const divisionB =
        Math.floor(b / a) % 2 === 0 ? Math.floor(b / a) : Math.floor(b / a) - 1;
      b -= divisionB * a;
    } else {
      return [a, b];
    }
  }
}

console.log(solve(6, 19));
console.log(solve(2, 1));
console.log(solve(22, 5));
console.log(solve(2, 10));
console.log(solve(100000000000, 3));
