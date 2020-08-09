package main

import (
	"fmt"
	"testing"
)

func TestBasicTests(t *testing.T) {
	input1 := []int{22, -6, 32, 82, 9, 25}
	input2 := []int{68, -1, 1, -7, 10, 10}
	input3 := []int{11, -11}
	input4 := []int{-56, -85, 72, -26, -14, 76, -27, 72, 35, -21, -67, 87, 0, 21, 59, 27, -92, 68}
	input5 := []int{28, 38, -44, -99, -13, -54, 77, -51}
	input6 := []int{-1, -49, -1, 67, 8, -60, 39, 35}

	output1 := multipleOfIndex(input1)
	output2 := multipleOfIndex(input2)
	output3 := multipleOfIndex(input3)
	output4 := multipleOfIndex(input4)
	output5 := multipleOfIndex(input5)
	output6 := multipleOfIndex(input6)

	expectedOutput1 := []int{-6, 32, 25}
	expectedOutput2 := []int{-1, 10}
	expectedOutput3 := []int{-11}
	expectedOutput4 := []int{-85, 72, 0, 68}
	expectedOutput5 := []int{38, -44, -99}
	expectedOutput6 := []int{-49, 8, -60, 35}

	if !compareIntSlices(output1, expectedOutput1) {
		t.Errorf("Test 1 Failed. Output: %#v || ExpectedOutput: %#v\n", output1, expectedOutput1)
	} else {
		fmt.Printf("Test 1 Passed.\n")
	}

	if !compareIntSlices(output2, expectedOutput2) {
		t.Errorf("Test 2 Failed. Output: %#v || ExpectedOutput: %#v\n", output2, expectedOutput2)
	} else {
		fmt.Printf("Test 2 Passed.\n")
	}

	if !compareIntSlices(output3, expectedOutput3) {
		t.Errorf("Test 3 Failed. Output: %#v || ExpectedOutput: %#v\n", output3, expectedOutput3)
	} else {
		fmt.Printf("Test 3 Passed.\n")
	}

	if !compareIntSlices(output4, expectedOutput4) {
		t.Errorf("Test 4 Failed. Output: %#v || ExpectedOutput: %#v\n", output4, expectedOutput4)
	} else {
		fmt.Printf("Test 4 Passed.\n")
	}

	if !compareIntSlices(output5, expectedOutput5) {
		t.Errorf("Test 5 Failed. Output: %#v || ExpectedOutput: %#v\n", output5, expectedOutput5)
	} else {
		fmt.Printf("Test 5 Passed.\n")
	}

	if !compareIntSlices(output6, expectedOutput6) {
		t.Errorf("Test 6 Failed. Output: %#v || ExpectedOutput: %#v\n", output6, expectedOutput6)
	} else {
		fmt.Printf("Test 6 Passed.\n")
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
