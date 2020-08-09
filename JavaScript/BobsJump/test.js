const countWays = require("./index");

test("countWays is a function", () => {
  expect(typeof countWays).toEqual("function");
});

test("countWays works correctly - 1, 3", () => {
  expect(countWays(1, 3)).toEqual(1);
});

test("countWays works correctly - 3, 3", () => {
  expect(countWays(3, 3)).toEqual(4);
});

test("countWays works correctly - 2, 3", () => {
  expect(countWays(2, 3)).toEqual(2);
});

test("countWays works correctly - 5, 3", () => {
  expect(countWays(5, 3)).toEqual(13);
});

test("countWays works correctly - 4, 3", () => {
  expect(countWays(4, 3)).toEqual(7);
});

test("countWays works correctly - 10, 6", () => {
  expect(countWays(10, 6)).toEqual(492);
});

test("countWays works correctly - 14, 7", () => {
  expect(countWays(14, 7)).toEqual(7936);
});
