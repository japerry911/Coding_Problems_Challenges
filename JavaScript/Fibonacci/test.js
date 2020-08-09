const Fibonacci = require("./index");

test("nthFibo is a function", () => {
  expect(typeof Fibonacci).toEqual("function");
});

test("nthFibo correctly works - 4", () => {
  expect(Fibonacci(4)).toEqual(2);
});

test("nthFibo correctly works - 10", () => {
  expect(Fibonacci(10)).toEqual(34);
});

test("nthFibo correctly works - 20", () => {
  expect(Fibonacci(20)).toEqual(4181);
});
