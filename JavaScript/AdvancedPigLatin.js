/*
---Advanced Pig Latin---
Pig latin is created by taking all the consonants before the first vowel 
of a word and moving them to the back of the word followed by the letters "ay".

"hello" => "ellohay"
"creating" => "eatingcray"
If the first letter of the word is a vowel, the string is left the same and the 
letters "way" are appended to the end.

"algorithm" => "algorithmway"
This problem is different from other variations in that it expects casing to remain 
the same so:

"Hello World" => "Ellohay Orldway"
as well as punctuation.

"Pizza? Yes please!" => "Izzapay? Esyay easeplay!"
Your job is to take a string and translate it to Pig Latin. The string will never be 
undefined but may contain both numbers and letters. A word will never be a combination 
of numbers and letters. Also, there will never be punctuation at the beginning of a word 
and the only capital letter in a word will be the first letter meaning there are zero all 
capitalized words.
*/

console.log(translate("everyone."));

function translate(sentence) {
  const vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"];
  let sentenceArray = sentence.split(" ");
  let returnSentence = [];
  const punctuationRegExp = new RegExp("[^A-Za-z]");

  for (let word of sentenceArray) {
    if (vowels.indexOf(word[0]) > -1) {
      let punctuationObject = {};
      for (let i = 0; i < word.length; ++i) {
        if (punctuationRegExp.test(word[i])) {
          if (punctuationObject[word[i]] === undefined) {
            punctuationObject[word[i]] = [];
          }
          punctuationObject[word[i]].push(i);
        }
      }

      let useWord = word.concat("way");
      if (Object.keys(punctuationObject).length > 0) {
        let wordArray = useWord.replace(/[^A-Za-z]/g, "").split("");
        for (let i = 0; i < Object.keys(punctuationObject).length; ++i) {
          for (
            let r = 0;
            r < punctuationObject[Object.keys(punctuationObject)[i]].length;
            ++r
          ) {
            wordArray.push(Object.keys(punctuationObject)[i]);
          }
        }
        useWord = wordArray.join("");
      }

      returnSentence.push(useWord);
    } else {
      let vowelIndex = -1;
      for (let i = 0; i < word.length; ++i) {
        if (vowels.indexOf(word[i]) > -1) {
          vowelIndex = i;
          break;
        }
      }

      let punctuationObject = {};

      for (let i = 0; i < word.length; ++i) {
        if (punctuationRegExp.test(word[i])) {
          if (punctuationObject[word[i]] === undefined) {
            punctuationObject[word[i]] = [];
          }
          punctuationObject[word[i]].push(i);
        }
      }

      if (vowelIndex > -1) {
        let upperCase = word[0] === word[0].toUpperCase();

        word = word.toLowerCase();
        let newWord = word
          .substring(vowelIndex, word.length)
          .concat(word.substring(0, vowelIndex));

        let useWord = newWord;
        if (upperCase) {
          const wordArray = newWord.split("");
          useWord =
            newWord[0].toUpperCase() +
            wordArray.slice(1, wordArray.length).join("");
        }

        let useWord2 = useWord.concat("ay");
        if (Object.keys(punctuationObject).length > 0) {
          const wordArray = useWord2.replace(/[^A-Za-z]/g, "").split("");
          for (let i = 0; i < Object.keys(punctuationObject).length; ++i) {
            for (
              let r = 0;
              r < punctuationObject[Object.keys(punctuationObject)[i]].length;
              ++r
            ) {
              wordArray.push(Object.keys(punctuationObject)[i]);
            }
          }
          useWord2 = wordArray.join("");
        }

        returnSentence.push(useWord2);
      } else {
        returnSentence.push(word);
      }
    }
  }

  return returnSentence.join(" ");
}

String.prototype.replaceAt = function (index, replacement) {
  return (
    this.substr(0, index) +
    replacement +
    this.substr(index + replacement.length)
  );
};
