/*
You will have a list of rationals in the form

lst = [ [numer_1, denom_1] , ... , [numer_n, denom_n] ]
or

lst = [ (numer_1, denom_1) , ... , (numer_n, denom_n) ]
where all numbers are positive integers. You have to produce their sum N / D in an irreducible form: this means that N and D have only 1 as a common divisor.
*/

function sumFracts(l) {
  // Check if length is 0, if so return null
  if (l.length === 0) {
    return null;
  }

  // Start the Lowest Denomator & multiplier variable by selecting first denomator
  let ldm = l[0][1];
  let multiplier = l[0][1];

  // Loop through and find the largest denomator
  for (let i = 1; i < l.length; i++) {
    if (ldm < l[i][1]) {
      ldm = l[i][1];
      multiplier = l[i][1];
    }
  }

  // Loop through and find the lowest common denomator
  let finishBool = false;
  while (!finishBool) {
    for (let i = 0; i < l.length; i++) {
      if (ldm % l[i][1] === 0) {
        finishBool = true;
      } else {
        finishBool = false;
        break;
      }
    }

    if (!finishBool) {
      ldm += multiplier;
    }
  }

  // Create the final numerator
  let top = 0;
  for (let i = 0; i < l.length; i++) {
    top += (ldm / l[i][1]) * l[i][0];
  }

  // Return a whole number or the most reduced version of fraction
  if (top % ldm === 0) {
    return top / ldm;
  } else {
    return reduce(top, ldm);
  }
}

// Taken from: https://www.geeksforgeeks.org/reduce-a-fraction-to-its-simplest-form-by-using-javascript/
// Reduces fraction to it's simpliest form by finding the Greatest Common Denomator &
// dividing it
function reduce(numer, denomin) {
  var gcd = function gcd(a, b) {
    return b ? gcd(b, a % b) : a;
  };
  gcd = gcd(numer, denomin);
  return [numer / gcd, denomin / gcd];
}
