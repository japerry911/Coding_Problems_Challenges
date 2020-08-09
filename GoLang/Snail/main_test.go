package main

import (
	"fmt"
	"testing"
)

func TestSnailTestsFunction(t *testing.T) {
	input1 := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	input2 := [][]int{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}

	output1 := Snail(input1)
	output2 := Snail(input2)

	expectedOutput1 := []int{1, 2, 3, 6, 9, 8, 7, 4, 5}
	expectedOutput2 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}

	if !compareIntSlices(output1, expectedOutput1) {
		t.Errorf("Test 1 Failed. Output: %#v || ExpectedOutput: %#v", output1, expectedOutput1)
	} else {
		fmt.Println("Test 1 Passed.")
	}

	if !compareIntSlices(output2, expectedOutput2) {
		t.Errorf("Test 2 Failed. Output: %#v || ExpectedOutput: %#v", output2, expectedOutput2)
	} else {
		fmt.Println("Test 2 Passed.")
	}
}

func compareIntSlices(a []int, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	for i, aVal := range a {
		if b[i] != aVal {
			return false
		}
	}

	return true
}
