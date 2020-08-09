/*
---Bob's Jump---
Bob has ladder. He wants to climb this ladder, but being a precocious child, 
he wonders about exactly how many ways he could to climb this n size ladder 
using jumps of up to distance k.

Consider this example...

n = 5
k = 3

Here, Bob has ladder of length 5, and with each jump, he can ascend up to 3 
steps (he can either jump step 1 or 2 or 3). This gives the below possibilities

1 1 1 1 1
1 1 1 2
1 1 2 1 
1 2 1 1
2 1 1 1
1 2 2
2 2 1
2 1 2
1 1 3
1 3 1
3 1 1
2 3
3 2
Your task to calculate number of ways to climb ladder of length n with upto k 
steps for Bob. (13 in above case)

Constraints:

1<=n<=150
1<=k<=50
Tip: don't go hard way; there's easy way.
*/

function countWays(n, k) {
  const DP = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    let sum = 0;
    for (let j = i - k; j < i; j++) {
      sum += DP[j] || 0;
    }
    DP[i] = sum + (i < k ? 1 : 0);
  }
  return DP[n - 1];

  /*let possibleNumbers = [];
  let ways = new Array(n + 1).fill(0);
  ways[0] = 1;

  for (let i = 1; i <= k; ++i) {
    possibleNumbers.push(i);
  }

  for (let i = 1; i <= n; ++i) {
    for (let a = 0; a < possibleNumbers.length; ++a) {
      if (i >= possibleNumbers[a]) {
        ways[i] += ways[i - possibleNumbers[a]];
      }
    }
  }

  return ways[n];*/
}

console.log(countWays(125, 46));
//2.1267647932546565e+37

module.exports = countWays;
