/*
---parseInt() Reloaded---
In this kata we want to convert a string into an integer. The strings simply represent the numbers in words.

Examples:

"one" => 1
"twenty" => 20
"two hundred forty-six" => 246
"seven hundred eighty-three thousand nine hundred and nineteen" => 783919
Additional Notes:

The minimum number is "zero" (inclusively)
The maximum number, which must be supported is 1 million (inclusively)
The "and" in e.g. "one hundred and twenty-four" is optional, in some cases it's present and in others it's not
All tested numbers are valid, you don't need to validate them
*/

function parseInt(string) {
  const lookUpObject = {
    zero: 0,
    one: 1,
    two: 2,
    three: 3,
    four: 4,
    five: 5,
    six: 6,
    seven: 7,
    eight: 8,
    nine: 9,
    ten: 10,
    eleven: 11,
    twelve: 12,
    thirteen: 13,
    fourteen: 14,
    fifteen: 15,
    sixteen: 16,
    seventeen: 17,
    eighteen: 18,
    nineteen: 19,
    twenty: 20,
    thirty: 30,
    forty: 40,
    fifty: 50,
    sixty: 60,
    seventy: 70,
    eighty: 80,
    ninety: 90,
  };

  let returnNumber = 0;
  const formattedInput = string.replace(/ and /g, " ").split(" ");

  let segmentSum = 0;
  for (let i = 0; i < formattedInput.length; ++i) {
    if (formattedInput[i + 1] === "million") {
      returnNumber += 1000000;
    } else if (formattedInput[i + 1] === "hundred") {
      if (formattedInput[i + 2] === "thousand") {
        segmentSum += lookUpObject[formattedInput[i]] * 100;
        segmentSum *= 1000;
        returnNumber += segmentSum;
        segmentSum = 0;
        i += 2;
      } else {
        segmentSum += lookUpObject[formattedInput[i]] * 100;
        ++i;
      }
    } else if (formattedInput[i + 1] === "thousand") {
      if (formattedInput[i].indexOf("-") > -1) {
        const breakInput = formattedInput[i].split("-");
        segmentSum += lookUpObject[breakInput[0]];
        segmentSum += lookUpObject[breakInput[1]];
      } else {
        if (lookUpObject[formattedInput[i]] !== undefined) {
          console.log(segmentSum, formattedInput[i]);
          segmentSum += lookUpObject[formattedInput[i]];
          console.log(segmentSum, formattedInput[i]);
        }
      }

      returnNumber += segmentSum * 1000;
      segmentSum = 0;
    } else {
      if (formattedInput[i].indexOf("-") > -1) {
        const breakInput = formattedInput[i].split("-");
        segmentSum += lookUpObject[breakInput[0]];
        segmentSum += lookUpObject[breakInput[1]];
      } else {
        if (lookUpObject[formattedInput[i]] !== undefined) {
          segmentSum += lookUpObject[formattedInput[i]];
        }
      }
    }
  }

  returnNumber += segmentSum;

  return returnNumber;
}

module.exports = parseInt;
