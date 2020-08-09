/*
Complete the solution so that it splits the string into pairs of two characters. If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

Examples:

solution('abc') // should return ['ab', 'c_']
solution('abcdef') // should return ['ab', 'cd', 'ef']
*/

function solution(str) {
  // Declare the return Array, and split up input string into character array
  let returnArray = [];
  const splitInput = str.split("");

  // Declare a previous value to look back on and loop through and create the split strings
  let previousValue = splitInput[0];
  for (let i = 1; i < splitInput.length; i++) {
    if (i % 2 === 1) {
      returnArray.push(previousValue.concat(splitInput[i]));
    } else {
      previousValue = splitInput[i];
    }
  }

  // Check if the split string length is odd, if it is, add on the previous value (last)
  // plus an underscore
  if (splitInput.length % 2 === 1) {
    returnArray.push(previousValue.concat("_"));
  }

  return returnArray;
}
