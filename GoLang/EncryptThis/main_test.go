package main

import (
	"fmt"
	"strings"
	"testing"
)

func TestSampleTests(t *testing.T) {
	input1 := ""
	input2 := "A wise old owl lived in an oak"
	input3 := "The more he saw the less he spoke"
	input4 := "The less he spoke the more he heard"
	input5 := "Why can we not all be like that wise old bird"
	input6 := "Thank you Piotr for all your help"

	output1 := EncryptThis(input1)
	output2 := EncryptThis(input2)
	output3 := EncryptThis(input3)
	output4 := EncryptThis(input4)
	output5 := EncryptThis(input5)
	output6 := EncryptThis(input6)

	expectedOutput1 := ""
	expectedOutput2 := "65 119esi 111dl 111lw 108dvei 105n 97n 111ka"
	expectedOutput3 := "84eh 109ero 104e 115wa 116eh 108sse 104e 115eokp"
	expectedOutput4 := "84eh 108sse 104e 115eokp 116eh 109ero 104e 104dare"
	expectedOutput5 := "87yh 99na 119e 110to 97ll 98e 108eki 116tah 119esi 111dl 98dri"
	expectedOutput6 := "84kanh 121uo 80roti 102ro 97ll 121ruo 104ple"

	if strings.Compare(output1, expectedOutput1) != 0 {
		t.Errorf("Test 1 Failed. Output: %s || ExpectedOutput: %s\n", output1, expectedOutput1)
	} else {
		fmt.Println("Test 1 Passed.")
	}

	if strings.Compare(output2, expectedOutput2) != 0 {
		t.Errorf("Test 2 Failed. Output: %s || ExpectedOutput: %s\n", output2, expectedOutput2)
	} else {
		fmt.Println("Test 2 Passed.")
	}

	if strings.Compare(output3, expectedOutput3) != 0 {
		t.Errorf("Test 3 Failed. Output: %s || ExpectedOutput: %s\n", output3, expectedOutput3)
	} else {
		fmt.Println("Test 3 Passed.")
	}

	if strings.Compare(output4, expectedOutput4) != 0 {
		t.Errorf("Test 4 Failed. Output: %s || ExpectedOutput: %s\n", output4, expectedOutput4)
	} else {
		fmt.Println("Test 4 Passed.")
	}

	if strings.Compare(output5, expectedOutput5) != 0 {
		t.Errorf("Test 5 Failed. Output: %s || ExpectedOutput: %s\n", output5, expectedOutput5)
	} else {
		fmt.Println("Test 5 Passed.")
	}

	if strings.Compare(output6, expectedOutput6) != 0 {
		t.Errorf("Test 6 Failed. Output: %s || ExpectedOutput: %s\n", output6, expectedOutput6)
	} else {
		fmt.Println("Test 6 Passed.")
	}
}
