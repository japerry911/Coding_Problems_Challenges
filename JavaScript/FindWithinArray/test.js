const findInArray = require("./index");

const trueIfEven = function (v, i) {
  return v % 2 === 0;
};
const neverTrue = function (v, i) {
  return false;
};
const trueIfValueEqualsIndex = function (v, i) {
  return v === i;
};
const trueIfLengthEqualsIndex = function (v, i) {
  return v.length === i;
};

test("findInArray is a function", () => {
  expect(typeof findInArray).toEqual("function");
});

test("findInArray works correctly - [] TrueIfEven", () => {
  expect(findInArray([], trueIfEven)).toEqual(-1);
});

test("findInArray works correctly - [1,3,5,6,7], trueIfEven", () => {
  expect(findInArray([1, 3, 5, 6, 7], trueIfEven)).toEqual(3);
});

test("findInArray works correctly - [2,4,6,8], trueIfEven)", () => {
  expect(findInArray([2, 4, 6, 8], trueIfEven)).toEqual(0);
});

test("findInArray works correctly - [2,4,6,8], neverTrue", () => {
  expect(findInArray([2, 4, 6, 8], neverTrue)).toEqual(-1);
});

test("findInArray works correctly - [13,5,3,1,4,5], trueIfValueEqualsIndex)", () => {
  expect(findInArray([13, 5, 3, 1, 4, 5], trueIfValueEqualsIndex)).toEqual(4);
});

test('findInArray works correctly - ["one","two","three","four","five","six"], trueIfLengthEqualsIndex', () => {
  expect(
    findInArray(
      ["one", "two", "three", "four", "five", "six"],
      trueIfLengthEqualsIndex
    )
  ).toEqual(4);
});

test('findInArray works correctly - ["bc","af","d","e"], trueIfLengthEqualsIndex)', () => {
  expect(findInArray(["bc", "af", "d", "e"], trueIfLengthEqualsIndex)).toEqual(
    -1
  );
});
