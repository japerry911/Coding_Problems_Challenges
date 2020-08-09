const balancedNum = require("./index");

test("balancedNum is a function", () => {
  expect(typeof balancedNum).toEqual("function");
});

test("balancedNum works correctly - 7", () => {
  expect(balancedNum(7)).toEqual("Balanced");
});

test("balancedNum works correctly - 959", () => {
  expect(balancedNum(959)).toEqual("Balanced");
});

test("balancedNum works correctly - 13", () => {
  expect(balancedNum(13)).toEqual("Balanced");
});

test("balancedNum works correctly - 432", () => {
  expect(balancedNum(432)).toEqual("Not Balanced");
});

test("balancedNum works correctly - 424", () => {
  expect(balancedNum(424)).toEqual("Balanced");
});

test("balancedNum works correctly - 1024", () => {
  expect(balancedNum(1024)).toEqual("Not Balanced");
});

test("balancedNum works correctly - 66545", () => {
  expect(balancedNum(66545)).toEqual("Not Balanced");
});

test("balancedNum works correctly - 295591", () => {
  expect(balancedNum(295591)).toEqual("Not Balanced");
});

test("balancedNum works correctly - 1230987", () => {
  expect(balancedNum(1230987)).toEqual("Not Balanced");
});

test("balancedNum works correctly - 56239814", () => {
  expect(balancedNum(56239814)).toEqual("Balanced");
});
