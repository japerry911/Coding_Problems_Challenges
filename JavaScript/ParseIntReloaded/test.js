const parseInt = require("./index");

test("parseInt is a function", () => {
  expect(typeof parseInt).toEqual("function");
});

test("parseInt works correctly - Test 1", () => {
  expect(parseInt("one")).toEqual(1);
});

test("parseInt works correctly - Test 2", () => {
  expect(parseInt("twenty")).toEqual(20);
});

test("parseInt works correctly - Test 3", () => {
  expect(parseInt("two hundred forty-six")).toEqual(246);
});

test("parseInt works correctly - Test 4", () => {
  expect(
    parseInt("seven hundred eighty-three thousand nine hundred and nineteen")
  ).toEqual(783919);
});

test("parseInt works correctly - Test 5", () => {
  expect(parseInt("five hundred thousand three hundred")).toEqual(500300);
});

test("parseInt works correctly - Test 6", () => {
  expect(parseInt("two hundred thousand and three")).toEqual(200003);
});

test("parseInt works correctly - Test 7", () => {
  expect(parseInt("two hundred thousand three")).toEqual(200003);
});

test("parseInt works correctly - Test 8", () => {
  expect(parseInt("seven hundred thousand")).toEqual(700000);
});
