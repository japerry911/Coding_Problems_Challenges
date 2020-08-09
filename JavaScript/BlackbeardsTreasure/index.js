/*
---Blackbeards Treasure---
It was a long, hard voyage with many battles, but finally 
you've found Captain Blackbeard's treasure room. It's full 
of treasure chests! But they all have combination locks.

The locks:
Each lock has two or more numbers anywhere from 1 to 100 000. 
They are labeled with letters, but the letters do not change 
(they're just labels). Examples:

A (number reel) B (number reel)
E (number reel) R (number reel) Y (number reel)

The Clues:
Because Blackbeard had such a poor memory, he's written clues on 
the bottom of each chest. Example:

Clue: "A2B4C6"

You figure out that if you divide each number by the greatest common 
factor, it gives you the correct code to the chest. Examples:

Clue: "A2B4C6"

Gretest common factor = 2
2 / 2 = 1
4 / 2 = 2
6 / 2 = 3

Code: "A1B2C3"

More examples:

Clue: "T3Y3U9E6" Code: "T1Y1U3E2"
Clue: "M3H7" Code: "M3H7"
Clue: "Y14U7I7P21 Code: "Y2U1I1P3"

Task:
Write a function treasureCode(), that accepts a String parameter and 
returns the correct code as a String.

Input: String. Two or more letter number combinations. The letter will
be one uppercase character A-Z. The number can be from 1 to 100 000.

Output: String.

Good luck!
*/

function treasureCode(clue) {
  const chestCodeHolder = {};
  const letters = [];
  let numbers = [];
  let previousLetter = null;
  let numberSubArray = undefined;

  for (const character of clue.split("")) {
    if (/[a-z]/i.test(character)) {
      previousLetter = character;
      chestCodeHolder[previousLetter] = [];
      letters.push(character);

      if (numberSubArray !== undefined && numberSubArray.length > 0) {
        numbers.push(numberSubArray);
      }

      numberSubArray = [];
    } else {
      chestCodeHolder[previousLetter].push(character);
      numberSubArray.push(character);
    }
  }

  if (numberSubArray.length > 0) {
    numbers.push(numberSubArray);
  }

  numbers = numbers.map((numberArray) => Number(numberArray.join("")));

  const gcd = findGCD(numbers);

  let returnCode = "";
  for (let i = 0; i < letters.length; ++i) {
    returnCode += letters[i] + (numbers[i] / gcd).toString();
  }

  return returnCode;
}

function gcd(a, b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

function findGCD(arr) {
  let result = arr[0];
  for (let i = 1; i < arr.length; i++) {
    result = gcd(arr[i], result);

    if (result == 1) {
      return 1;
    }
  }
  return result;
}

module.exports = treasureCode;
/*
var integer = 12;
var i;
for (i = 2; i <= integer; i++) {
  if (integer % i == 0) {
    console.log(i);
    integer = integer / i;
    i = i - 1;
  }
}*/
