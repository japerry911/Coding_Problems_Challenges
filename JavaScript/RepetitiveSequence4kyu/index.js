/*
---Repetitive Sequence 4 KYU---
Yet another easy kata!

Task:
Let's write a sequence starting with seq = [0, 1, 2, 2] in which
0 and 1 occurs 1 time
2 occurs 2 time
and sequence advances with adding next natural number seq[natural number] times so now, 3 appears 2 times and 
so on.

Input
You are given input n and return nth(0-based) value of this list.
let;s take example:

seq = [0, 1, 2, 2]
i = 3 and as seq[i]=2, seq = [0, 1, 2, 2, 3, 3]
i = 4 and as seq[i]=3, seq = [0, 1, 2, 2, 3, 3, 4, 4, 4]
i = 5 and as seq[i]=3, seq = [0, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5] and so on.

Some elements of list:

[0, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 
11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 
15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 
19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21]

Constraint :
Python
0 <= n <= 2412^{41}2 
41
 
Javascript
0 <= n <= 2492^{49}2 
49
 
Have fun!
tip: you can solve this using smart brute-force.
*/

function find(n) {
  const sequenceArray = [0, 1, 2, 2, 3, 3];

  if (n < sequenceArray.length) {
    return sequenceArray[n];
  }

  let currentIndex = sequenceArray.length;
  let currentRepeatValue = 3;
  let currentValue = 4;
  let lengths = [2];
  let index = 0;

  for (;;) {
    const cachedLength = lengths[index];
    const cachedLengthsLength = lengths.length;
    ++index;

    if (index >= 1000000) {
      lengths.splice(0, index);
      index = 0;
    }

    if (currentIndex + cachedLength * currentRepeatValue >= n) {
      for (let i = 0; i < cachedLength; ++i) {
        currentIndex += currentRepeatValue;

        if (currentIndex > n) {
          console.log(index);
          return currentValue;
        } else if (currentIndex === n) {
          return ++currentValue;
        }

        ++currentValue;
      }
    } else {
      currentIndex += cachedLength * currentRepeatValue;
      currentValue += cachedLength;
      if (cachedLengthsLength < 1000000)
        for (let i = 0; i < cachedLength; ++i) {
          lengths.push(currentRepeatValue);
        }
    }

    ++currentRepeatValue;
  }

  /*for (;;) {
    const cachedLength = lengths[index];
    const cachedLengthsLength = lengths.length;
    ++index;

    for (let i = 0; i < cachedLength; ++i) {
      currentIndex += currentRepeatValue;

      if (currentIndex > n) {
        return currentValue;
      }

      if (cachedLengthsLength < 70000) lengths.push(currentRepeatValue);

      ++currentValue;
    }

    ++currentRepeatValue;
  }*/

  /*const sequenceArray = [0, 1, 2, 2, 3, 3];

  if (n <= 5) {
    return sequenceArray[n];
  }

  let outerRepeat = 2;
  let innerRepeat = 3;
  let currentIndex = 5;
  let currentValue = 4;

  for (;;) {
    for (let i = 0; i < outerRepeat; ++i) {
      currentIndex += innerRepeat;

      if (currentIndex > n) {
        return currentValue;
      }

      ++currentValue;
    }
  }*/

  /*const sequenceArray = [0, 1, 2, 2, 3, 3];

  if (n <= 5) {
    return sequenceArray[n];
  }

  let currentRepeatCount = 3;
  let repeatsLeft = 2;
  let currentValue = 3;
  let currentIndices = 5;

  for (;;) {
    for (let i = 0; i < repeatsLeft; ++i) {
      currentIndices += currentRepeatCount;

      if (currentIndices >= n) {
        return currentValue;
      }

      ++currentValue;
    }

    ++currentRepeatCount;
  }*/

  /*sequenceArray.splice(0, 3);

  let currentValue = 3;
  let counter = 3;
  let fullBreak = false;

  for (;;) {
    for (let i = 0; i < sequenceArray[0]; ++i) {
      sequenceArray.push(currentValue);
      ++counter;
      if (counter === n) {
        fullBreak = true;
        break;
      }
    }

    if (fullBreak) {
      break;
    }

    sequenceArray.shift();

    ++currentValue;
  }

  return sequenceArray[sequenceArray.length - 1];*/
  /*const sequenceArray = [0, 1, 2, 2];
  for (let i = 3; i <= n; ++i) {
    for (let r = 0; r < sequenceArray[i]; ++r) {
      sequenceArray.push(i);
    }
  }
  let counter = 2500;
  for (let i of sequenceArray) {
    console.log(i);
    --counter;
    if (counter === 0) return;
  }

  return sequenceArray[n];*/
}

console.log(find(348534616977225));
/*console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
console.log(find(1797656802755));
//console.log(find(5000));
//console.log(find(116));
//console.log(find(1658929602350));*/

module.exports = find;
