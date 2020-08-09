const Skiponacci = require("./index");

test("skiponacci is a function", () => {
  expect(typeof Skiponacci).toEqual("function");
});

test("skiponacci works correctly - 1", () => {
  expect(Skiponacci(1)).toEqual("1");
});

test("skiponacci works correctly - 5", () => {
  expect(Skiponacci(5)).toEqual("1 skip 2 skip 5");
});

test("skiponacci works correctly - 7", () => {
  expect(Skiponacci(7)).toEqual("1 skip 2 skip 5 skip 13");
});
