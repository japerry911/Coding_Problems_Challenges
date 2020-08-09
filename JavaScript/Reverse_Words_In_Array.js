/*
Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

Examples: spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" spinWords( "This is a test") => returns "This is a test" spinWords( "This is another test" )=> returns "This is rehtona test"
*/

function spinWords(inputWords){
    // Transform input words into an array with split, also declare empty return array
    const wordsArray = inputWords.split(' ');
    const returnArray = [];

    // For loop through words in wordsArray
    for (let i = 0; i < wordsArray.length; i++) {
        // If word is greater than or equal to 5 letters, it is reversed, otherwise just added
        // to returnArray
        if (wordsArray[i].length >= 5) {
        returnArray.push(wordsArray[i].split('').reverse().join(''));
        } else {
        returnArray.push(wordsArray[i]);
        }
    }

    // Turn returnArray back into sentence and return it
    return returnArray.join(' ');
}