package main

import (
	"fmt"
	"testing"
)

func TestSampleTests(t *testing.T) {
	input1 := 0
	input2 := 1
	input3 := 2
	input4 := 3

	output1 := MultiplicationTable(input1)
	output2 := MultiplicationTable(input2)
	output3 := MultiplicationTable(input3)
	output4 := MultiplicationTable(input4)

	expectedOutput1 := [][]int{}
	expectedOutput2 := [][]int{{1}}
	expectedOutput3 := [][]int{{1, 2}, {2, 4}}
	expectedOutput4 := [][]int{{1, 2, 3}, {2, 4, 6}, {3, 6, 9}}

	if !compare2IntSlices(output1, expectedOutput1) {
		t.Errorf("Test 1 Failed. Output: %#v || ExpectedOutput: %#v\n", output1, expectedOutput1)
	} else {
		fmt.Println("Test 1 Passed.")
	}

	if !compare2IntSlices(output2, expectedOutput2) {
		t.Errorf("Test 2 Failed. Output: %#v || ExpectedOutput: %#v\n", output2, expectedOutput2)
	} else {
		fmt.Println("Test 2 Passed.")
	}

	if !compare2IntSlices(output3, expectedOutput3) {
		t.Errorf("Test 3 Failed. Output: %#v || ExpectedOutput: %#v\n", output3, expectedOutput3)
	} else {
		fmt.Println("Test 3 Passed.")
	}

	if !compare2IntSlices(output4, expectedOutput4) {
		t.Errorf("Test 4 Failed. Output: %#v || ExpectedOutput: %#v\n", output4, expectedOutput4)
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
