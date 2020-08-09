/*
---Skiponacci Sequence---
Your task is to generate the Fibonacci sequence to n places, with each alternating value as "skip". For example:

"1 skip 2 skip 5 skip 13 skip 34"

Return the result as a string

You can presume that n is always a positive integer between (and including) 1 and 64.
*/

function skiponacci(n) {
  if (n === 1) {
    return "1";
  } else if (n === 2) {
    return "1 skip";
  }

  const solutionArray = ["1", "skip"];
  let currentIndex = 2;
  let previousValue = 1;
  let currentValue = 1;
  let cache = 0;
  let numberBool = true;

  while (currentIndex < n) {
    cache = currentValue;
    currentValue += previousValue;
    previousValue = cache;

    if (numberBool) {
      solutionArray.push(currentValue.toString());
      numberBool = false;
    } else {
      solutionArray.push("skip");
      numberBool = true;
    }

    ++currentIndex;
  }

  return solutionArray.join(" ");
}

module.exports = skiponacci;
