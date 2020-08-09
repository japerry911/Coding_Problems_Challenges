const PrimeIndexSum = require("./index");

test("total is a function", () => {
  expect(typeof PrimeIndexSum.total).toEqual("function");
});

test("isPrime is a function", () => {
  expect(typeof PrimeIndexSum.isPrime).toEqual("function");
});

test("total works correctly - Array 1", () => {
  expect(PrimeIndexSum.total([])).toEqual(0);
});

test("total works correctly - Array 2", () => {
  expect(PrimeIndexSum.total([1, 2, 3, 4])).toEqual(7);
});

test("total works correctly - Array 3", () => {
  expect(PrimeIndexSum.total([1, 2, 3, 4, 5, 6])).toEqual(13);
});

test("total works correctly - Array 4", () => {
  expect(PrimeIndexSum.total([1, 2, 3, 4, 5, 6, 7, 8])).toEqual(21);
});

test("total works correctly - Array 5", () => {
  expect(PrimeIndexSum.total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11])).toEqual(21);
});

test("total works correctly - Array 6", () => {
  expect(
    PrimeIndexSum.total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13])
  ).toEqual(33);
});

test("total works correctly - Array 7", () => {
  expect(
    PrimeIndexSum.total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
  ).toEqual(47);
});
