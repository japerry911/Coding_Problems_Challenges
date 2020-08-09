const crack = require("./index");

test("crack is a function", () => {
  expect(typeof crack).toEqual("function");
});

test("crack works correctly - Test 1", () => {
  expect(crack("827ccb0eea8a706c4c34a16891f84e7b")).toEqual("12345");
});

test("crack works correctly - Test 2", () => {
  expect(crack("86aa400b65433b608a9db30070ec60cd")).toEqual("00078");
});
