package main

import (
	"fmt"
	"testing"
)

func TestBitCountingTests(t *testing.T) {
	input1 := uint(0)
	input2 := uint(4)
	input3 := uint(7)
	input4 := uint(9)
	input5 := uint(10)
	input6 := uint(1234)

	output1 := CountBits(input1)
	output2 := CountBits(input2)
	output3 := CountBits(input3)
	output4 := CountBits(input4)
	output5 := CountBits(input5)
	output6 := CountBits(input6)

	expectedOutput1 := 0
	expectedOutput2 := 1
	expectedOutput3 := 3
	expectedOutput4 := 2
	expectedOutput5 := 2
	expectedOutput6 := 5

	if output1 != expectedOutput1 {
		t.Errorf("Test 1 Failed. Output: %d || ExpectedOutput: %d\n", output1, expectedOutput1)
	} else {
		fmt.Println("Test 1 Passed.")
	}

	if output2 != expectedOutput2 {
		t.Errorf("Test 2 Failed. Output: %d || ExpectedOutput: %d\n", output2, expectedOutput2)
	} else {
		fmt.Println("Test 2 Passed.")
	}

	if output3 != expectedOutput3 {
		t.Errorf("Test 3 Failed. Output: %d || ExpectedOutput: %d\n", output3, expectedOutput3)
	} else {
		fmt.Println("Test 3 Passed.")
	}

	if output4 != expectedOutput4 {
		t.Errorf("Test 4 Failed. Output: %d || ExpectedOutput: %d\n", output4, expectedOutput4)
	} else {
		fmt.Println("Test 4 Passed.")
	}

	if output5 != expectedOutput5 {
		t.Errorf("Test 5 Failed. Output: %d || ExpectedOutput: %d\n", output5, expectedOutput5)
	} else {
		fmt.Println("Test 5 Passed.")
	}

	if output6 != expectedOutput6 {
		t.Errorf("Test 6 Failed. Output: %d || ExpectedOutput: %d\n", output6, expectedOutput6)
	} else {
		fmt.Println("Test 6 Passed.")
	}
}
