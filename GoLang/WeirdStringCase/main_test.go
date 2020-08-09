package main

import (
	"fmt"
	"strings"
	"testing"
)

func TestSampleTests(t *testing.T) {
	input1 := "abc def"
	input2 := "ABC"
	input3 := "This is a test Looks like you passed"

	output1 := toWeirdCase(input1)
	output2 := toWeirdCase(input2)
	output3 := toWeirdCase(input3)

	expectedOutput1 := "AbC DeF"
	expectedOutput2 := "AbC"
	expectedOutput3 := "ThIs Is A TeSt LoOkS LiKe YoU PaSsEd"

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
}
