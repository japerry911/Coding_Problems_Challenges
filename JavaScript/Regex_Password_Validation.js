/*
You need to write regex that will validate a password to make sure it meets the following criteria:

At least six characters long
contains a lowercase letter
contains an uppercase letter
contains a number
Valid passwords will only be alphanumeric characters.
*/

function validate(password) {
  // Regex
  // (?=\S{6,}$) => Password must be at least 6 characters
  // (?=\S*[A-Z]) => The password must contain 1 Upper Case character
  // (?=\S*[a-z]) => The password must contain 1 Lower Case character
  // (?=\S*[0-9]) => The password must contain a digit
  return /^(?=\S{6,}$)(?=\S*[A-Z])(?=\S*[a-z])(?=\S*[0-9])[A-Za-z0-9]*$/.test(password);
}