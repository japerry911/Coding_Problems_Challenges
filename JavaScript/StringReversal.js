/*
---String Reversal---
In this Kata, we are going to reverse a string while maintaining spaces.

For example:

solve("our code") = "edo cruo"
-- Normal reversal without spaces is "edocruo". 
-- However, there is a space after the first three characters, hence "edo cruo"

solve("your code rocks") = "skco redo cruoy"
solve("codewars") = "srawedoc"
More examples in the test cases. All input will be lower case letters and in some cases spaces.

Good luck!
*/

function solve(str) {
  let indexCounter = -1;
  return str
    .split("")
    .map((val, index) => {
      if (indexCounter >= str.replace(/ /g, "").split("").reverse().length) {
        return;
      } else if (val === " ") {
        return val;
      } else {
        ++indexCounter;
        return str.replace(/ /g, "").split("").reverse()[indexCounter];
      }
    })
    .join("");
}

console.log(solve("your code rocks"));
