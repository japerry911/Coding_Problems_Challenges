/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

isIsogram("Dermatoglyphics") == true
isIsogram("aba") == false
isIsogram("moOse") == false // -- ignore letter case
*/

function isIsogram(str){
  // Used in checking if a letter has occurred
  let obj_check = {};
  
  // For loop for looping through lowercase string and check if letter has been used
  for (let i = 0; i < str.length; i++) {
    if (obj_check[str.toLowerCase()[i]] === undefined) {
      obj_check[str.toLowerCase()[i]] = 1;
    } else {
      return false;
    }
  }
  
  return true;
}