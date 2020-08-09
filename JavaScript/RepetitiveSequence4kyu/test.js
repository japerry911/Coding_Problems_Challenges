const RepetitiveSeqFind = require("./index");

test("find is a function", () => {
  expect(typeof RepetitiveSeqFind).toEqual("function");
});

test("find works correctly", () => {
  const testValues = [
    [0, 0],
    [1, 1],
    [2, 2],
    [3, 2],
    [4, 3],
    [5, 3],
    [6, 4],
    [7, 4],
    [8, 4],
    [9, 5],
    [10, 5],
    [11, 5],
    [12, 6],
    [13, 6],
    [14, 6],
    [15, 6],
    [16, 7],
    [17, 7],
    [18, 7],
    [19, 7],
  ];

  for (const [n, expected] of testValues) {
    expect(RepetitiveSeqFind(n)).toEqual(expected);
  }
});
