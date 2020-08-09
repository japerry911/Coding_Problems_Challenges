/*
---Sudoku Solver---
Write a function that will solve a 9x9 Sudoku puzzle. 
The function will take one argument consisting of the 
2D puzzle array, with the value 0 representing an unknown square.

The Sudokus tested against your function will be "easy" 
(i.e. determinable; there will be no need to assume and test 
possibilities on unknowns) and can be solved with a brute-force approach.

For Sudoku rules, see the Wikipedia article.
*/

sudoku([
    [8, 0, 0, 2, 0, 0, 0, 0, 4],
    [0, 0, 0, 0, 0, 7, 0, 3, 5],
    [3, 0, 4, 0, 0, 0, 0, 6, 0],
    [0, 0, 0, 0, 0, 0, 3, 1, 9],
    [0, 0, 2, 5, 0, 0, 0, 0, 6],
    [0, 0, 0, 0, 8, 6, 0, 0, 0],
    [7, 0, 0, 0, 0, 0, 0, 9, 0],
    [0, 0, 0, 0, 0, 3, 0, 0, 0],
    [0, 9, 6, 0, 0, 0, 5, 0, 0]
])

function sudoku(puzzle) {
  const emptySpots = findEmptySpots(puzzle);
  const limit = 9;

  for (let i = 0; i < emptySpots.length;) {
      const row = emptySpots[i][0];
      const column = emptySpots[i][1];

      let value = puzzle[row][column] + 1;
      let found = false;

      while (!found && value <= limit) {
          if (validateValue(puzzle, row, column, value)) {
              puzzle[row][column] = value;
              found = true;
              ++i
          } else {
              ++value;
          }
      }

      if (!found) {
          puzzle[row][column] = 0;
          --i;
      }
  }

  console.log(puzzle);

  return puzzle;
}

function findEmptySpots(puzzle) {
    let emptySpots = [];
    
    for (let r = 0; r < puzzle.length; ++r) {
        for (let c = 0; c < puzzle[r].length; ++c) {
            if (puzzle[r][c] === 0) {
                emptySpots.push([r, c]);
            }
        }
    }

    return emptySpots;
}

function checkRow(puzzle, row, value) {
    for (let colItem of puzzle[row]) {
        if (colItem === value) {
            return false;
        }
    }

    return true;
}

function checkColumn(puzzle, column, value) {
    for (let r = 0; r < puzzle.length; ++r) {
        if (puzzle[r][column] === value) {
            return false;
        }
    }

    return true;
}

function checkBox(puzzle, row, column, value) {
    let startRow;
    let startColumn;

    if (row % 3 === 0) {
        startRow = row
    } else {
        startRow = row - (row % 3);
    }

    if (column % 3 === 0) {
        startColumn = column;
    } else {
        startColumn = column - (column % 3);
    }

    for (let r = startRow; r < startRow + 3; ++r) {
        for (let c = startColumn; c < startColumn + 3; ++c) {
            if (puzzle[r][c] === value) {
                return false;
            }
        }
    }

    return true;
}

function validateValue(puzzle, row, column, value) {
    if (checkRow(puzzle, row, value) && checkColumn(puzzle, column, value) &&
    checkBox(puzzle, row, column, value)) {
        return true;
    }

    return false;
}

module.exports.sudoku = sudoku;
module.exports.findEmptySpots = findEmptySpots;
module.exports.checkRow = checkRow;
module.exports.checkColumn = checkColumn;
module.exports.checkBox = checkBox;
module.exports.validateValue = validateValue;