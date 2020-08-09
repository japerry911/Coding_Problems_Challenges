/*
---Calculator---
Create a simple calculator that given a string of operators (), +, -, *, / 
and numbers separated by spaces returns the value of that expression

Example:

Calculator().evaluate("2 / 2 + 3 * 4 - 6") # => 7
Calculator().evaluate("2 * (2 + 3) * (4 - 6)") # => -20
Remember about the order of operations! Multiplications and divisions have a higher 
priority and should be performed left-to-right. Additions and subtractions have a 
lower priority and should also be performed left-to-right.
*/

function calculate(string) {
  const operatorsMap = {
    "*": 2,
    "/": 2,
    "+": 1,
    "-": 1,
  };
  let returnValue = 0;
  const stringArray = string.split(" ");

  // Check for Parenthesis
  const parenthesisBool = stringArray.indexOf("(") > -1;

  if (parenthesisBool) {
    let inParenthesis = false;
    let parenthesisValue;
    let parenthesisOperator = "+";
    let startingIndex;

    for (let i = 0; i < stringArray.length; ++i) {
      const element = stringArray[i];

      if (element === "(") {
        inParenthesis = true;
        parenthesisValue = 0;
        startingIndex = i;
      } else if (element === ")") {
        stringArray.splice(
          startingIndex,
          i - startingIndex + 1,
          parenthesisValue
        );

        inParenthesis = false;
        i -= startingIndex + 3;
      } else if (inParenthesis && operatorsMap[element] === undefined) {
        switch (parenthesisOperator) {
          case "+":
            parenthesisValue += parseFloat(element);
            break;
          case "-":
            parenthesisValue -= parseFloat(element);
            break;
          case "*":
            parenthesisValue *= parseFloat(element);
            break;
          case "/":
            parenthesisValue /= parseFloat(element);
            break;
        }
      } else if (inParenthesis && operatorsMap[element] !== undefined) {
        parenthesisOperator = element;
      }
    }
  }

  for (let o = 2; o > 0; --o) {
    let leftNumber = undefined;
    let rightNumber = undefined;
    let nextBool = false;
    let operator;
    for (let i = 0; i < stringArray.length; ++i) {
      if (i < 0) {
        continue;
      } else if (
        operatorsMap[stringArray[i]] === undefined &&
        leftNumber === undefined &&
        o === operatorsMap[stringArray[i + 1]]
      ) {
        leftNumber = parseFloat(stringArray[i]);
        operator = stringArray[i + 1];
      } else if (
        operatorsMap[stringArray[i]] === undefined &&
        leftNumber &&
        nextBool
      ) {
        rightNumber = parseFloat(stringArray[i]);

        switch (operator) {
          case "+":
            leftNumber += rightNumber;
            break;
          case "-":
            leftNumber -= rightNumber;
            break;
          case "*":
            leftNumber *= rightNumber;
            break;
          case "/":
            leftNumber /= rightNumber;
            break;
        }

        stringArray.splice(i - 2, 3, leftNumber);
        i -= 3;
        leftNumber = undefined;
        rightNumber = undefined;
        nextBool = false;
        operator = undefined;
      } else if (o === operatorsMap[stringArray[i]]) {
        nextBool = true;
      }
    }
  }

  let total = parseFloat(stringArray[0]);
  if (stringArray.length > 1) {
    switch (stringArray[1]) {
      case "+":
        total = parseFloat(stringArray[0]) + parseFloat(stringArray[2]);
        break;
      case "-":
        total = parseFloat(stringArray[0]) - parseFloat(stringArray[2]);
    }
  }

  return total;
}

module.exports.calculate = calculate;
