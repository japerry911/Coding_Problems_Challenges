package main

import (
	"fmt"
	"testing"
)

func TestExampleTests(t *testing.T) {
	input1 := []int{}
	input2 := []int{1, 2, 3, 4}
	input3 := []int{1, 2, 3, 4, 5, 6}
	input4 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

	output1 := Solve(input1)
	output2 := Solve(input2)
	output3 := Solve(input3)
	output4 := Solve(input4)

	expectedOutput1 := 0
	expectedOutput2 := 7
	expectedOutput3 := 13
	expectedOutput4 := 47

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
}
