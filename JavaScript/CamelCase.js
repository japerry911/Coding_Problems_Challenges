/*
---Camel Case---
Write simple .camelCase method (camel_case function in PHP, 
CamelCase in C# or camelCase in Java) for strings. All words 
must have their first letter capitalized without spaces.

For instance:

"hello case".camelCase() => HelloCase
"camel case word".camelCase() => CamelCaseWord
Don't forget to rate this kata! Thanks :)
*/

String.prototype.camelCase = function () {
  let returnString = "";
  let capitalize = true;

  for (let i = 0; i < this.toString().length; ++i) {
    if (capitalize && this.toString()[i] !== " ") {
      returnString += this.toString()[i].toUpperCase();
      capitalize = false;
    } else if (this.toString()[i] === " ") {
      capitalize = true;
    } else {
      returnString += this.toString()[i];
    }
  }

  return returnString;
};
