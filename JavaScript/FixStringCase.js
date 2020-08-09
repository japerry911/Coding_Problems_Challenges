/*
---Fix String Case---
In this Kata, you will be given a string that may have mixed 
uppercase and lowercase letters and your task is to convert that 
string to either lowercase only or uppercase only based on:

make as few changes as possible.
if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
For example:

solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
More examples in test cases. Good luck!
*/

function solve(s) {
  const caseObject = { lower: 0, upper: 0 };
  let stringArray = s.split("");

  for (let i = 0; i < stringArray.length; ++i) {
    if (stringArray[i] === stringArray[i].toUpperCase()) {
      ++caseObject["upper"];
    } else {
      ++caseObject["lower"];
    }
  }

  let upperCase = false;
  if (caseObject["upper"] > caseObject["lower"]) {
    upperCase = true;
  }

  for (let i = 0; i < stringArray.length; ++i) {
    if (upperCase && stringArray[i] !== stringArray[i].toUpperCase()) {
      stringArray[i] = stringArray[i].toUpperCase();
    } else if (!upperCase && stringArray[i] !== stringArray[i].toLowerCase()) {
      stringArray[i] = stringArray[i].toLowerCase();
    }
  }

  return stringArray.join("");
}
