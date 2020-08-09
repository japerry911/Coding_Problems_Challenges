package main

import (
	"fmt"
	"testing"
)

func TestBasictTests(t *testing.T) {
	input1 := "codewarriors"
	input2 := "suoidea"
	input3 := "ultrarevolutionariees"
	input4 := "strengthlessnesses"
	input5 := "cuboideonavicuare"
	input6 := "chrononhotonthuooaos"
	input7 := "iiihoovaeaaaoougjyaw"

	output1 := Solve(input1)
	output2 := Solve(input2)
	output3 := Solve(input3)
	output4 := Solve(input4)
	output5 := Solve(input5)
	output6 := Solve(input6)
	output7 := Solve(input7)

	expectedOutput1 := 2
	expectedOutput2 := 3
	expectedOutput3 := 3
	expectedOutput4 := 1
	expectedOutput5 := 2
	expectedOutput6 := 5
	expectedOutput7 := 8

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

	if output7 != expectedOutput7 {
		t.Errorf("Test 7 Failed. Output: %d || ExpectedOutput: %d\n", output7, expectedOutput7)
	} else {
		fmt.Println("Test 7 Passed.")
	}
}
