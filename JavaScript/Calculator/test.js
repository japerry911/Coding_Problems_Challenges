const Calculator = require("./index");

test("calculate is a function", () => {
  expect(typeof Calculator.calculate).toEqual("function");
});

/*test("Calculate works correctly - (1 + 3) * 4 * ( 5 - 3 )", () => {
  expect(Calculator.calculate("( 1 + 3 ) * 4 * ( 5 - 3 )")).toEqual(32);
});

test("Calculate works correctly - 127", () => {
  expect(Calculator.calculate("127")).toEqual(127);
});

test("Calculate works correctly - 2 + 3", () => {
  expect(Calculator.calculate("2 + 3")).toEqual(5);
});

test("Calculate works correctly - 2 - 3 - 4", () => {
  expect(Calculator.calculate("2 - 3 - 4")).toEqual(-5);
});

test("Calculate works correctly - 10 * 5 / 2", () => {
  expect(Calculator.calculate("10 * 5 / 2")).toEqual(25);
});

test("Calculate works correctly - ( 2 + 2 ) * ( 5 - 3 )", () => {
  expect(Calculator.calculate("( 2 + 2 ) * ( 5 - 3 )")).toEqual(8);
});

test("Calculate works correctly - 2 / 2 + 3 * 4 - 6", () => {
  expect(Calculator.calculate("2 / 2 + 3 * 4 - 6")).toEqual(7);
});

test("Calculate works correctly - 2 + 3 * 4 / 3 - 6 / 3 * 3 + 8", () => {
  expect(Calculator.calculate("2 + 3 * 4 / 3 - 6 / 3 * 3 + 8")).toEqual(8);
});*/

test("Calculate works correctly - 35 * 47 / 72 * 16 - 44", () => {
  expect(Calculator.calculate("35 * 47 / 72 * 16 - 44")).toEqual(321.555554);
});
