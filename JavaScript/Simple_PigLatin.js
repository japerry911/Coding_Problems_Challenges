/*
Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

Examples
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !
*/

function pigIt(str){
  // Convert input to an array and declare a array to store translated string
  const strArray = str.split(" ");
  let translatedString = [];

  // Loop through string array and check if it's punctuation/spec character, if it is
  // then skip. Otherwise, push up the pig latin translation of the word
  for (let i = 0; i < strArray.length; i++) {
    if (/[A-Za-z0-9]+/.test(strArray[i])) {
      translatedString.push(strArray[i].slice(1, strArray[i].length) + strArray[i][0] + "ay");
    } else {
      translatedString.push(strArray[i]);
    }
  }
  
  // Return the pig latin translated array converted to a string/sentence
  return translatedString.join(" ");
}