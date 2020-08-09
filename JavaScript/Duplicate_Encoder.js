/*
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 
Notes

Assertion messages may be unclear about what they display in some languages. If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!
*/

function duplicateEncode(word){
  // Create occurrences object and store each letter as key and the value is # of occurrences
  let occurrences_obj = {};
  for (let i = 0; i < word.length; i++) {
    if (occurrences_obj[word[i].toLowerCase()] === undefined) {
      occurrences_obj[word[i].toLowerCase()] = 1;
    } else {
      occurrences_obj[word[i].toLowerCase()] += 1;
    }
  }
  
  // Create encoded message, utilize the occurrences_obj to tell if it's ")" or "("
  let encoded_msg = "";
  for (var i = 0; i < word.length; i++) {
    if (occurrences_obj[word[i].toLowerCase()] > 1) {
      encoded_msg += ")";
    } else {
      encoded_msg += "(";
    }
  }
  
  return encoded_msg;
}
