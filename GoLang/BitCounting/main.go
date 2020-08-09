/*
---Bit Counting---
Write a function that takes an integer as input, and returns the number of bits that
are equal to one in the binary representation of that number. You can guarantee that
input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should
return 5 in this case
*/

package main

func main() {}

// CountBits Kata Function
func CountBits(num uint) int {
	var bits int
	var currentTwo int
	var powerOfTwo int
	exponent := 1
	uNum := int(num)

	for {
		currentTwo = 1 << uint(exponent)

		if currentTwo > uNum {
			break
		}

		powerOfTwo = currentTwo
		exponent++
	}

	if powerOfTwo == 0 {
		return 0
	}

	for {
		if powerOfTwo == 0 {
			uNum--
			bits++
		} else if uNum >= powerOfTwo {
			uNum -= powerOfTwo
			bits++
		}
		powerOfTwo /= 2
		if uNum <= 0 {
			break
		}
	}

	return bits
}
