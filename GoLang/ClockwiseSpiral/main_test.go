package main

import (
	"fmt"
	"testing"
)

func TestKataCreateSpiral(t *testing.T) {
	input1 := 1
	input2 := 2
	input3 := 3
	input4 := 4

	output1 := CreateSpiral(input1)
	output2 := CreateSpiral(input2)
	output3 := CreateSpiral(input3)
	output4 := CreateSpiral(input4)

	expectedOutput1 := [][]int{{1}}
	expectedOutput2 := [][]int{{1, 2}, {4, 3}}
	expectedOutput3 := [][]int{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}
	expectedOutput4 := [][]int{{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}}

	if !compare2IntSlices(output1, expectedOutput1) {
		t.Errorf("Test 1 Failed. Output: %#v || ExpectedOutput: %#v", output1, expectedOutput1)
	} else {
		fmt.Println("Test 1 Passed.")
	}

	if !compare2IntSlices(output2, expectedOutput2) {
		t.Errorf("Test 2 Failed. Output: %#v || ExpectedOutput: %#v", output2, expectedOutput2)
	} else {
		fmt.Println("Test 2 Passed.")
	}

	if !compare2IntSlices(output3, expectedOutput3) {
		t.Errorf("Test 3 Failed. Output: %#v || ExpectedOutput: %#v", output3, expectedOutput3)
	} else {
		fmt.Println("Test 3 Passed.")
	}

	if !compare2IntSlices(output4, expectedOutput4) {
		t.Errorf("Test 4 Failed. Output: %#v || ExpectedOutput: %#v", output4, expectedOutput4)
	} else {
		fmt.Println("Test 4 Passed.")
	}
}

func compare2IntSlices(a [][]int, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}

	for i, v := range a {
		if len(v) != len(b[i]) {
			return false
		}
		for ii, vv := range v {
			if vv != b[i][ii] {
				return false
			}
		}
	}

	return true
}
