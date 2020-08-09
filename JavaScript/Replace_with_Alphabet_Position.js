/*
In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example
alphabetPosition("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" (as a string)
*/

function alphabetPosition(text) {
  // Declaring Return String (array to start) & regex to check if char is a letter
  let returnString = [];
  const regExpLettersOnly = /[A-Za-z]/
  
  // For loop through the inputted text and utilize charCodeAt to get the Ascii Number
  // and subtract the base lowercase a from it (96) (also make every letter lowercase to start)
  for (let i = 0; i < text.length; i++) {
    if (regExpLettersOnly.test(text[i])) {
      returnString.push((text[i].toLowerCase().charCodeAt() - 96).toString());
    }
  }
  
  return returnString.join(" ");
}