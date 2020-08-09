const solution = require("./index");

test("solution is a function", () => {
  expect(typeof solution).toEqual("function");
});

test("solution works correctly - XXI", () => {
  expect(solution("XXI")).toEqual(21);
});

test("solution works correctly - I", () => {
  expect(solution("I")).toEqual(1);
});

test("solution works correctly - IV", () => {
  expect(solution("IV")).toEqual(4);
});

test("solution works correctly - MMVIII", () => {
  expect(solution("MMVIII")).toEqual(2008);
});

test("solution works correctly - MDCLXVI", () => {
  expect(solution("MDCLXVI")).toEqual(1666);
});
