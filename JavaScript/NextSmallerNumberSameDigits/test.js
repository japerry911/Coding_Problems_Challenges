const NextSmaller = require("./index");

test("nextSmaller is a function", () => {
  expect(typeof NextSmaller.nextSmaller).toEqual("function");
});

test("nextSmaller works correctly - 9", () => {
  expect(NextSmaller.nextSmaller(9)).toEqual(-1);
});

test("nextSmaller works correctly - 111", () => {
  expect(NextSmaller.nextSmaller(111)).toEqual(-1);
});

test("nextSmaller works correctly - 135", () => {
  expect(NextSmaller.nextSmaller(135)).toEqual(-1);
});

test("nextSmaller works correctly - 1027", () => {
  expect(NextSmaller.nextSmaller(1027)).toEqual(-1);
});

test("nextSmaller works correctly - 21", () => {
  expect(NextSmaller.nextSmaller(21)).toEqual(12);
});

test("nextSmaller works correctly - 531", () => {
  expect(NextSmaller.nextSmaller(531)).toEqual(513);
});

test("nextSmaller works correctly - 2071", () => {
  expect(NextSmaller.nextSmaller(2071)).toEqual(2017);
});

test("nextSmaller works correctly - 907", () => {
  expect(NextSmaller.nextSmaller(907)).toEqual(790);
});

test("nextSmaller works correctly - 414", () => {
  expect(NextSmaller.nextSmaller(414)).toEqual(144);
});

test("nextSmaller works correctly - 2017", () => {
  expect(NextSmaller.nextSmaller(2017)).toEqual(1720);
});

test("nextSmaller works correctly - 2061", () => {
  expect(NextSmaller.nextSmaller(2061)).toEqual(2016);
});

test("nextSmaller works correctly - 2067", () => {
  expect(NextSmaller.nextSmaller(2067)).toEqual(-1);
});

test("nextSmaller works correctly - 1234567908", () => {
  expect(NextSmaller.nextSmaller(1234567908)).toEqual(1234567890);
});

test("nextSmaller works correctly - 123456789", () => {
  expect(NextSmaller.nextSmaller(123456789)).toEqual(-1);
});
