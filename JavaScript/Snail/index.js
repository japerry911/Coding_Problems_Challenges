/*
---Snail---
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
*/

function snail(array) {
  if (array.length === 0) {
    return [];
  } else if (array.length === 1) {
    return array[0];
  }

  const returnArray = [];

  let startColumn = 0;
  let endColumn = array.length - 1;
  let startRow = 0;
  let endRow = endColumn;

  while (startColumn <= endColumn && startRow <= endRow) {
    for (let i = startColumn; i <= endColumn; ++i) {
      returnArray.push(array[startRow][i]);
    }
    ++startRow;

    for (let i = startRow; i <= endRow; ++i) {
      returnArray.push(array[i][endColumn]);
    }
    --endColumn;

    for (let i = endColumn; i >= startColumn; --i) {
      returnArray.push(array[endRow][i]);
    }
    --endRow;

    for (let i = endRow; i >= startRow; --i) {
      returnArray.push(array[i][startColumn]);
    }
    ++startColumn;
  }

  return returnArray;
}

module.exports = snail;
