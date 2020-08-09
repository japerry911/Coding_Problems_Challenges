const humanReadable = require("./index");

test("humanReadable is a function", () => {
  expect(typeof humanReadable).toEqual("function");
});

test("humanReadable works correctly - 0", () => {
  expect(humanReadable(0)).toEqual("00:00:00");
});

test("humanReadable works correctly - 5", () => {
  expect(humanReadable(5)).toEqual("00:00:05");
});

test("humanReadable works correctly - 60", () => {
  expect(humanReadable(60)).toEqual("00:01:00");
});

test("humanReadable works correctly - 86399", () => {
  expect(humanReadable(86399)).toEqual("23:59:59");
});

test("humanReadable works correctly - 359999", () => {
  expect(humanReadable(359999)).toEqual("99:59:59");
});
