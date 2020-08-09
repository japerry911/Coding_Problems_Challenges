/*
---Sum of Prime Indexed Numbers---
In this Kata, you will be given an integer array and your task is
to return the sum of elements occupying prime-numbered indices.

The first element of the array is at index 0.

Good luck!
*/

package main

import (
	"math"
)

func main() {}

// Solve Kata Function
func Solve(arr []int) int {
	primeSlice := generatePrimes(len(arr))
	var primeIndexSum int

	for i, v := range arr {
		if containsInt(primeSlice, i) {
			primeIndexSum += v
		}
	}

	return primeIndexSum
}

func containsInt(slice []int, number int) bool {
	for _, v := range slice {
		if number == v {
			return true
		}
	}
	return false
}

func generatePrimes(n int) []int {
	var primeSlice []int
	boolSlice := make([]bool, n)
	limit := int(math.Sqrt(float64(n)))

	for i := 2; i <= limit; i++ {
		if !boolSlice[i] {
			for x := i * i; x < n; x += i {
				boolSlice[x] = true
			}
		}
	}

	for i := 2; i < n; i++ {
		if !boolSlice[i] {
			primeSlice = append(primeSlice, i)
		}
	}

	return primeSlice
}

/*
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
*/
