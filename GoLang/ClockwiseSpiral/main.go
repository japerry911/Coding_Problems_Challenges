/*
---Clockwise Spiral---
Do you know how to make a spiral? Let's test it!
Classic definition: A spiral is a curve which emanates from a
central point, getting progressively farther away as it revolves around the point.

Your objective is to complete a function createSpiral(N) that receives an
integer N and returns an NxN two-dimensional array with numbers 1 through NxN
represented as a clockwise spiral.

Return an empty array if N < 1 or N is not int / number

Examples:

N = 3 Output: [[1,2,3],[8,9,4],[7,6,5]]

1    2    3
8    9    4
7    6    5
N = 4 Output: [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]

1   2   3   4
12  13  14  5
11  16  15  6
10  9   8   7
N = 5 Output: [[1,2,3,4,5],[16,17,18,19,6],[15,24,25,20,7],[14,23,22,21,8],[13,12,11,10,9]]

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9
*/

package main

import (
	"math"
)

func main() {}

// CreateSpiral Kata Function
func CreateSpiral(n int) [][]int {
	if n < 1 {
		return [][]int{}
	} else if n == 1 {
		return [][]int{{1}}
	}

	var startRow int
	var startColumn int
	maxCounter := int(math.Pow(float64(n), 2))
	counter := 1
	endRow := n - 1
	endColumn := n - 1
	returnSpiral := make([][]int, n)

	for i := range returnSpiral {
		returnSpiral[i] = make([]int, n)
	}

	for {
		for i := startColumn; i <= endColumn; i++ {
			returnSpiral[startRow][i] = counter
			counter++
		}
		startRow++

		for i := startRow; i <= endRow; i++ {
			returnSpiral[i][endColumn] = counter
			counter++
		}
		endColumn--

		for i := endColumn; i >= startColumn; i-- {
			returnSpiral[endRow][i] = counter
			counter++
		}
		endRow--

		for i := endRow; i >= startRow; i-- {
			returnSpiral[i][startColumn] = counter
			counter++
		}
		startColumn++

		if counter > maxCounter {
			break
		}
	}

	return returnSpiral
}
