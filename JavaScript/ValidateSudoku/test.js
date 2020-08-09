const SudokuValidator = require("./index");

test("isValid is a function", () => {
  expect(typeof SudokuValidator.isValid).toEqual("function");
});

test("validateBoxesColumnsRows is a function", () => {
  expect(typeof SudokuValidator.validateBoxesColumnsRows).toEqual("function");
});

test("isValid works correctly - board 1", () => {
  expect(
    SudokuValidator.isValid([
      [7, 8, 4, 1, 5, 9, 3, 2, 6],
      [5, 3, 9, 6, 7, 2, 8, 4, 1],
      [6, 1, 2, 4, 3, 8, 7, 5, 9],

      [9, 2, 8, 7, 1, 5, 4, 6, 3],
      [3, 5, 7, 8, 4, 6, 1, 9, 2],
      [4, 6, 1, 9, 2, 3, 5, 8, 7],

      [8, 7, 6, 3, 9, 4, 2, 1, 5],
      [2, 4, 3, 5, 6, 1, 9, 7, 8],
      [1, 9, 5, 2, 8, 7, 6, 3, 4],
    ])
  ).toBeTruthy();
});

test("isValid works correctly - board 2", () => {
  expect(
    SudokuValidator.isValid([
      [1, 4, 2, 3],
      [3, 2, 4, 1],

      [4, 1, 3, 2],
      [2, 3, 1, 4],
    ])
  ).toBeTruthy();
});

test("isValid works correctly - board 3", () => {
  expect(
    SudokuValidator.isValid([
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],

      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],

      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
    ])
  ).toBeFalsy();
});

test("isValid works correctly - board 4", () => {
  expect(
    SudokuValidator.isValid([[1, 2, 3, 4, 5], [1, 2, 3, 4], [1, 2, 3, 4], [1]])
  ).toBeFalsy();
});

test("isValid works correctly - board 5", () => {
  expect(
    SudokuValidator.isValid([
      [1, 2, 3, 4, 5, 6, 7, 8, 9],
      [2, 3, 1, 5, 6, 4, 8, 9, 7],
      [3, 1, 2, 6, 4, 5, 9, 7, 8],
      [4, 5, 6, 7, 8, 9, 1, 2, 3],
      [5, 6, 4, 8, 9, 7, 2, 3, 1],
      [6, 4, 5, 9, 7, 8, 3, 1, 2],
      [7, 8, 9, 1, 2, 3, 4, 5, 6],
      [8, 9, 7, 2, 3, 1, 5, 6, 4],
      [9, 7, 8, 3, 1, 2, 6, 4, 5],
    ])
  ).toBeFalsy();
});
