/*
Write a function which makes a list of strings representing all of the ways you can balance n pairs of parentheses

Examples
balancedParens(0) => [""]
balancedParens(1) => ["()"]
balancedParens(2) => ["()()","(())"]
balancedParens(3) => ["()()()","(())()","()(())","(()())","((()))"]
*/

function balancedParens(n) {
  // Checks if n is 0, if so it return an empty string in an array
  if (n === 0) {
    return [''];
  }
  
  // Declaring return array
  let parenArray = [];   

  // Main recursive function used in generating parenthesises
  function generator(open_number, closed_number, combo_str) {
    // If the open parenthesis number is === 0 AND the closed number is also 0 AND
    // if the combination parenthesis element is greater than 0, then add it to the return array
    if (!open_number && !closed_number && combo_str.length) {
      parenArray.push(combo_str);
    } 
    
    // If the open number is greater than 0, then rerun the generator recursive function
    // also add to the combo_str an open parenthesis
    if (open_number) {
      generator(open_number - 1, closed_number, combo_str + '(');
    } 
    
    // If the closed number is greater than the open_number, then rerun the generator recursive function
    // also add to the combo_str a closed parenthesis
    if (open_number < closed_number) {
      generator(open_number, closed_number - 1, combo_str + ')');
    }
  }
  
  // Calling of the initial instance of generator
  generator(n, n, '');
  
  // Return the return array
  return parenArray;
}
