/*
Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/

function high(x){
  // Declare variables and split up the input x at each space into array
  let returnWord;
  let highScore = 0;
  const splitX = x.split(' ');
  
  // Loop through the array X (each word) and then loop through each letter within each word
  // and calculate the score of that word with charCodeAt() ascii number minus 96 to
  // equalize it to position in alphabet
  for (let i = 0; i < splitX.length; i++) {
    let currentScore = 0;
    for (let r = 0; r < splitX[i].length; r++) {
      currentScore += splitX[i][r].charCodeAt() - 96;
    }
    
    // Replace the current highScore/returnWord if the current word's score is greater
    if (highScore < currentScore) {
      highScore = currentScore;
      returnWord = splitX[i];
    }
  }
  
  // Return return word
  return returnWord;
}