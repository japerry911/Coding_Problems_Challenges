/*
---Weird String Case---
Write a function toWeirdCase (weirdcase in Ruby) that accepts a string, and
returns the same string with all even indexed characters in each word upper
cased, and all odd indexed characters in each word lower cased. The indexing
just explained is zero based, so the zero-ith index is even, therefore that
character should be upper cased.

The passed in string will only consist of alphabetical characters and spaces(' ').
Spaces will only be present if there are multiple words. Words will be separated by
a single space(' ').

Examples:
toWeirdCase("String") // => returns "StRiNg"
toWeirdCase("Weird string case") // => returns "WeIrD StRiNg CaSe"
*/

package main

import "strings"

func main() {}

// toWeirdCase Kata Function
func toWeirdCase(str string) string {
	var returnString string
	words := strings.Split(str, " ")

	for _, w := range words {
		for i, c := range w {
			if i%2 == 0 {
				returnString += strings.ToUpper(string(c))
			} else {
				returnString += strings.ToLower(string(c))
			}
		}
		returnString += " "
	}

	return returnString[:len(returnString)-1]
}
