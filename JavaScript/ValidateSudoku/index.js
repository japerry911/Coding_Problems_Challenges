/*
---Sudoku Validator---
Given a Sudoku data structure with size NxN, N > 0 and √N == integer, write a method to 
validate if it has been filled out correctly.

The data structure is a multi-dimensional Array, i.e:

[
  [7,8,4,  1,5,9,  3,2,6],
  [5,3,9,  6,7,2,  8,4,1],
  [6,1,2,  4,3,8,  7,5,9],

  [9,2,8,  7,1,5,  4,6,3],
  [3,5,7,  8,4,6,  1,9,2],
  [4,6,1,  9,2,3,  5,8,7],

  [8,7,6,  3,9,4,  2,1,5],
  [2,4,3,  5,6,1,  9,7,8],
  [1,9,5,  2,8,7,  6,3,4]
]
Rules for validation

Data structure dimension: NxN where N > 0 and √N == integer
Rows may only contain integers: 1..N (N included)
Columns may only contain integers: 1..N (N included)
'Little squares' (3x3 in example above) may also only contain integers: 1..N (N included)
*/

function isValid(puzzle) {
  const size = puzzle.length;
  const columnStore = {};
  const keyArray = new Array(size).fill(1).map((value, index) => value + index);
  const boxSize = Math.sqrt(size);
  let boxObject = {};
  let boxRowCounter = 0;

  for (let r = 0; r < size; ++r) {
    let boxCounter = 0;
    let boxNumber = 0;

    ++boxRowCounter;

    if (!validateBoxesColumnsRows(puzzle[r], keyArray, size)) {
      return false;
    }

    for (let c = 0; c < size; ++c) {
      if (columnStore[c] === undefined) {
        columnStore[c] = [];
      }

      if (boxObject[boxNumber] === undefined) {
        boxObject[boxNumber] = [];
      }

      boxObject[boxNumber].push(puzzle[r][c]);
      columnStore[c].push(puzzle[r][c]);

      ++boxCounter;
      if (boxCounter >= boxSize) {
        boxCounter = 0;
        ++boxNumber;
      }
    }

    if (boxRowCounter >= boxSize) {
      for (const boxNumber of Object.keys(boxObject)) {
        if (!validateBoxesColumnsRows(boxObject[boxNumber], keyArray, size)) {
          return false;
        }
      }

      boxObject = {};
      boxRowCounter = 0;
    }
  }

  for (const column of Object.keys(columnStore)) {
    if (!validateBoxesColumnsRows(columnStore[column], keyArray, size)) {
      return false;
    }
  }

  return true;
}

function validateBoxesColumnsRows(puzzleBoxColumnRow, keyArray, size) {
  const puzzleBoxColumnRowCopy = [...puzzleBoxColumnRow];
  return (
    puzzleBoxColumnRowCopy.length === size &&
    puzzleBoxColumnRowCopy
      .sort((a, b) => a - b)
      .every((element, index) => element === keyArray[index])
  );
}

module.exports.isValid = isValid;
module.exports.validateBoxesColumnsRows = validateBoxesColumnsRows;
