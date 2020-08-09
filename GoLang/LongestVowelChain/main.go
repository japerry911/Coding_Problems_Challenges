/*
---Longest Vowel Chain---
The vowel substrings in the word codewarriors are o,e,a,io.
The longest of these has a length of 2. Given a lowercase string
that has alphabetic characters only (both vowels and consonants)
and no spaces, return the length of the longest vowel substring.
Vowels are any of aeiou.

Good luck!
*/

package main

import (
	"log"
	"regexp"
)

func main() {}

// Solve Kata Function
func Solve(s string) int {
	vowelsRegex, err := regexp.Compile("[aeiou]")
	if err != nil {
		log.Fatalf("RegExp Compile Error: %s\n", err)
	}

	var longLength int
	var currentLength int

	for _, char := range s {
		if vowelsRegex.Match([]byte(string(char))) {
			currentLength++
		} else {
			if currentLength > longLength {
				longLength = currentLength
			}
			currentLength = 0
		}
	}

	if currentLength > longLength {
		longLength = currentLength
	}

	return longLength
}
