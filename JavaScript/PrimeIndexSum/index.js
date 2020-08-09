/*
---Sum of Prime Indices of an Array---
In this Kata, you will be given an integer array and 
your task is to return the sum of elements occupying prime-numbered indices.

The first element of the array is at index 0.

Good luck!
*/

function total(array) {
  let sum = 0;

  if (array.length <= 1) {
    return sum;
  }

  for (let i = 1; i < array.length; ++i) {
    if (isPrime(i)) {
      sum += array[i];
    }
  }

  return sum;
}

function isPrime(number) {
  if (number <= 1) {
    return false;
  }

  for (let i = 2; i < number; ++i) {
    if (number % i === 0) {
      return false;
    }
  }

  return true;
}

module.exports.total = total;
module.exports.isPrime = isPrime;
