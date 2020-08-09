/*
---Human Readable Time---
Write a function, which takes a non-negative integer (seconds) as 
input and returns the time in a human-readable format (HH:MM:SS)

HH = hours, padded to 2 digits, range: 00 - 99
MM = minutes, padded to 2 digits, range: 00 - 59
SS = seconds, padded to 2 digits, range: 00 - 59
The maximum time never exceeds 359999 (99:59:59)

You can find some examples in the test fixtures.
*/

function humanReadable(seconds) {
  let humanReadableTimeArray = [];

  if (seconds >= 3600) {
    humanReadableTimeArray.push(Math.floor(seconds / 3600));
    seconds %= 3600;
  } else {
    humanReadableTimeArray.push("00");
  }

  if (seconds >= 60) {
    humanReadableTimeArray.push(Math.floor(seconds / 60));
    seconds %= 60;
  } else {
    humanReadableTimeArray.push("00");
  }

  if (seconds >= 0) {
    humanReadableTimeArray.push(seconds);
  } else {
    humanReadableTimeArray.push("00");
  }

  humanReadableTimeArray = humanReadableTimeArray.map((element) =>
    element < 10 && element !== "00"
      ? "0".concat(element.toString())
      : element.toString()
  );

  return humanReadableTimeArray.join(":");
}

module.exports = humanReadable;
