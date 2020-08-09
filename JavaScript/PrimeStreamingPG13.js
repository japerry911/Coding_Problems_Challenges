/*
---Prime Streaming PG-13---
Create an endless stream of prime numbers - a bit like IntStream.of(2, 3, 5, 7, 11, 13, 17), 
but infinite. The stream must be able to produce a million primes in a few seconds.

If this is too easy, try Prime Streaming (NC-17).
*/

class Primes {
  static *stream() {
    for (let p of generatePrimes(0, 20000000)) {
      yield p;
    }
  }
}

function generatePrimes(a, b) {
  const primeArray = [];
  const limit = Math.sqrt(b);
  const boolArray = [];

  for (let i = 0; i < b; ++i) {
    boolArray.push(true);
  }

  for (let i = 2; i <= limit; ++i) {
    if (boolArray[i]) {
      for (let x = i * i; x < b; x += i) {
        boolArray[x] = false;
      }
    }
  }

  for (let i = 2; i < b; ++i) {
    if (boolArray[i]) {
      primeArray.push(i);
    }
  }

  return primeArray;
}
