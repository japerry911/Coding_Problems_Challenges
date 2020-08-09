/*
---Multiplication Table---
Your task, is to create NxN multiplication table, of size provided in parameter.

for example, when given size is 3:

1 2 3
2 4 6
3 6 9
for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]]
*/

package main

func main() {}

// MultiplicationTable Kata Function
func MultiplicationTable(size int) [][]int {
	multTable := make([][]int, size)
	for i := range multTable {
		multTable[i] = make([]int, size)
	}
	counter := 1

	for r := 1; r <= size; r++ {
		for c := 1; c <= size; c++ {
			multTable[r-1][c-1] = counter * c * r
		}
	}

	return multTable
}
