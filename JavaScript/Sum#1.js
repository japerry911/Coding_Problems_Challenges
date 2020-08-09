/*
---Sum #1---
PUZZLE #1. SUM

Assignment:

Write a function named sum which performs addition in the way shown below

sum(4)(5)(9)(); // => 18
sum(5)();       // => 5
sum();          // => 0
```ruby sum(4).(5).(9).() #=> 18 sum(5).() #=> 5 sum() #=> 0

NOTE: Pay attention that last brackets are left empty to indicate end of operations
*/

function sum(...args) {
  if (args.length === 0) return 0;

  let total = args.reduce(
    (accumulator, currentValue) => accumulator + currentValue,
    0
  );

  return function (...args2) {
    return args2.length == 0 ? total : sum(total, ...args2);
  };
}

console.log(sum(7)(5)(2)(10)());
console.log(sum());
