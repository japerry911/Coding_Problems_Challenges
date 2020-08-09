package main

import (
	"fmt"
	"testing"
)

func TestBasicTests(t *testing.T) {
	input1 := 8
	input2 := 111111
	input3 := 8675309

	output1 := SumEvenFibonacci(input1)
	output2 := SumEvenFibonacci(input2)
	output3 := SumEvenFibonacci(input3)

	expectedOutput1 := 10
	expectedOutput2 := 60696
	expectedOutput3 := 4613732

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
}
