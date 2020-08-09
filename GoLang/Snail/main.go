/*
---Snail---
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element,
traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a
clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
*/

package main

func main() {}

// Snail Kata Function
func Snail(snaipMap [][]int) []int {
	if len(snaipMap[0]) == 0 {
		return []int{}
	}

	var returnSlice []int

	startRow := 0
	endRow := len(snaipMap) - 1
	startColumn := 0
	endColumn := len(snaipMap) - 1

	for startRow <= endRow && startColumn <= endColumn {
		for i := startColumn; i <= endColumn; i++ {
			returnSlice = append(returnSlice, snaipMap[startRow][i])
		}
		startRow++

		for i := startRow; i <= endRow; i++ {
			returnSlice = append(returnSlice, snaipMap[i][endColumn])
		}
		endColumn--

		for i := endColumn; i >= startColumn; i-- {
			returnSlice = append(returnSlice, snaipMap[endRow][i])
		}
		endRow--

		for i := endRow; i >= startRow; i-- {
			returnSlice = append(returnSlice, snaipMap[i][startColumn])
		}
		startColumn++
	}

	return returnSlice
}
