/*
---Encrypt This---
Encrypt this!

You want to create secret messages which can be deciphered by the Decipher this! kata. Here are the conditions:

Your message is a string containing space separated words.
You need to encrypt each word in the message using the following rules:
The first letter needs to be converted to its ASCII code.
The second letter needs to be switched with the last letter
Keepin' it simple: There are no special characters in input.
Examples:
EncryptThis("Hello") == "72olle"
EncryptThis("good") == "103doo"
EncryptThis("hello world") == "104olle 119drlo"
*/

package main

import (
	"fmt"
	"strings"
)

func main() {}

// EncryptThis Kata Function
func EncryptThis(text string) string {
	if len(text) == 0 {
		return ""
	}

	var encryptedSlice []string
	wordsSlice := strings.Split(text, " ")

	for _, w := range wordsSlice {
		var encryptedWord string
		var lastLetter rune

		for i, c := range w {
			if i == 0 {
				encryptedWord += fmt.Sprintf("%d", c)
			} else if i == 1 && i < len(w)-1 {
				lastLetter = c
				encryptedWord += w[len(w)-1:]
			} else if i == len(w)-1 && i > 1 {
				encryptedWord += string(lastLetter)
			} else {
				encryptedWord += string(c)
			}
		}

		encryptedSlice = append(encryptedSlice, encryptedWord)
	}

	return strings.Join(encryptedSlice, " ")
}
