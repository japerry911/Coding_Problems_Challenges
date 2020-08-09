/*
Write a function called that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return true if the string is valid, and false if it's invalid.

Examples
"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true
Constraints
0 <= input.length <= 100
*/

function validParentheses(parens) {
  // Declared a checking array
  let ending_parenthesis = [];
  
  // Loop through and check for ending parenthesis
  for (var i = 0; i < parens.length; i++) {
    switch (parens[i]) {
      case "(":
        ending_parenthesis.push(")");
        break;
      case ")":
        if (ending_parenthesis[0] === ")") {
          ending_parenthesis.splice(0, 1);
        } else {
          return false;
        }
        break;
    }
  }
  
  return ending_parenthesis.length === 0;
} 