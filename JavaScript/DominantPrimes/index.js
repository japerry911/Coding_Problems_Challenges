/*
---Dominant Primes---
The prime number sequence starts with: 2,3,5,7,11. Notice that 2 is in position one.

3 occupies position two, which is a prime-numbered position. Similarly, 5 and 11 also 
occupy prime-numbered positions. We shall call primes such as 3,5,11 dominant primes 
because they occupy prime-numbered positions in the prime number sequence.

As you can see, for the prime range range(0,10), there are only two dominant primes (3 and 5), 
which occupy prime-numbered positions 2 and 3 in the prime number sequence, and the sum of these 
primes is: 3 + 5 = 8.

Given a range (a,b), what is the sum of dominant primes within that range? Note that a <= range <= 
b and b will not exceed 500000.

Good luck!
*/

function solve(a, b) {
  const primeArray = generatePrimes(a, b);
  const startingIndex = primeArray.findIndex((prime) => prime >= a);
  let sum = 0;

  for (let i = startingIndex; i < primeArray.length; ++i) {
    const currentIndex = i + 1;

    if (primeArray.indexOf(currentIndex) > -1) {
      sum += primeArray[i];
    }
  }

  return sum;
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

module.exports.solve = solve;
module.exports.generatePrimes = generatePrimes;
