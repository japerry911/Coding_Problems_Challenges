/*
In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.
The Morse code encodes every character as a sequence of "dots" and "dashes". For example, the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded as ·−−−−. The Morse code is case-insensitive, traditionally capital letters are used. When the message is written in Morse code, a single space is used to separate the character codes and 3 spaces are used to separate words. For example, the message HEY JUDE in Morse code is ···· · −·−− ·−−− ··− −·· ·.

NOTE: Extra spaces before or after the code have no meaning and should be ignored.

In addition to letters, digits and some punctuation, there are some special service codes, the most notorious of those is the international distress signal SOS (that was first issued by Titanic), that is coded as ···−−−···. These special codes are treated as single special characters, and usually are transmitted as separate words.

Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.

For example:

decodeMorse('.... . -.--   .--- ..- -.. .')
//should return "HEY JUDE"
NOTE: For coding purposes you have to use ASCII characters . and -, not Unicode characters.

The Morse code table is preloaded for you as a dictionary, feel free to use it:

Coffeescript/C++/Go/JavaScript/Julia/PHP/Python/Ruby/TypeScript: MORSE_CODE['.--']
C#: MorseCode.Get(".--") (returns string)
Elixir: @morse_codes variable (from use MorseCode.Constants). Ignore the unused variable warning for morse_codes because it's no longer used and kept only for old solutions.
Elm: MorseCodes.get : Dict String String
Haskell: morseCodes ! ".--" (Codes are in a Map String String)
Java: MorseCode.get(".--")
Kotlin: MorseCode[".--"] ?: "" or MorseCode.getOrDefault(".--", "")
Rust: self.morse_code
Scala: morseCodes(".--")
C: provides parallel arrays, i.e. morse[2] == "-.-" for ascii[2] == "C"
All the test strings would contain valid Morse code, so you may skip checking for errors and exceptions. In C#, tests will fail if the solution code throws an exception, please keep that in mind. This is mostly because otherwise the engine would simply ignore the tests, resulting in a "valid" solution.

Good luck!
*/

decodeMorse = function(morseCode) {
  // Create array from input, decode msg foundation, and previousSpace bool
  const morseCodeSplit = morseCode.split(" ");
  let decoded_msg = "";
  let previousSpace = false;
  
  // Look for leading spaces in morse code array and remove 
  if (morseCodeSplit[0] === "") {
    for (let i = 0; i < morseCodeSplit.length; i++) {
      if (morseCodeSplit[i] === "") {
        morseCodeSplit.splice(i, 1);
        i--;
      } else {
        break;
      }
    }
  }
  
  // Look for trailing spaces in morse code array and remove
  if (morseCodeSplit[morseCodeSplit.length - 1] === "") {
    for (let i = morseCodeSplit.length - 1; i >= 0; i--) {
      if (morseCodeSplit[i] === "") {
        morseCodeSplit.splice(i, 1);
      } else {
        break;
      }
    }
  }
  
  // Loop through updated morse code split array and decipher message using global MORSE_CODE
  // object and don't add extra not needed spaces
  for (let i = 0; i < morseCodeSplit.length; i++) {
    if (morseCodeSplit[i] === "") {
      if (previousSpace) {
        continue;
      } else {
        previousSpace = true;
        decoded_msg += " ";
        continue;
      }
    } else {
      previousSpace = false;
    }
  
    decoded_msg += MORSE_CODE[morseCodeSplit[i]];
  }
  
  return decoded_msg;
}