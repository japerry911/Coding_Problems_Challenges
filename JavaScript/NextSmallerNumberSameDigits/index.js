/*
---Next Smaller Number with Same Digits---
Write a function that takes a positive integer and returns the 
next smaller positive integer containing the same digits.

For example:

nextSmaller(21) == 12
nextSmaller(531) == 513
nextSmaller(2071) == 2017
Return -1 (for Haskell: return Nothing, for Rust: return None), when 
there is no smaller number that contains the same digits. Also return -1 
when the next smaller number with the same digits would require the leading 
digit to be zero.

nextSmaller(9) == -1
nextSmaller(111) == -1
nextSmaller(135) == -1
nextSmaller(1027) == -1 // 0721 is out since we don't write numbers with 
leading zeros
some tests will include very large numbers.
test data only employs positive integers.
*/

function nextSmaller(n) {
  if (n < 10) {
    return -1;
  }

  const numberStringArray = n.toString().split("");
  if (
    numberStringArray.filter((number) => number === numberStringArray[0])
      .length === numberStringArray.length
  ) {
    return -1;
  }

  function permute(permutation) {
    var length = permutation.length,
      result = [permutation.slice()],
      c = new Array(length).fill(0),
      i = 1,
      k,
      p;

    while (i < length) {
      if (c[i] < i) {
        k = i % 2 && c[i];
        p = permutation[i];
        permutation[i] = permutation[k];
        permutation[k] = p;
        ++c[i];
        i = 1;
        result.push(permutation.slice());
      } else {
        c[i] = 0;
        ++i;
      }
    }
    return result;
  }

  const permutations = permute(
    numberStringArray.map((number) => parseInt(number))
  )
    .map((element) => parseInt(element.join("")))
    .filter(
      (element) =>
        element < n &&
        element.toString().split("").length === numberStringArray.length
    )
    .sort((a, b) => b - a);

  return permutations.length === 0 ? -1 : permutations[0];
}

module.exports.nextSmaller = nextSmaller;
