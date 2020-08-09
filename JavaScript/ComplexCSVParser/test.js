const ParseCSV = require("./index");

test("Test that ParseCSV is a function.", () => {
  expect(typeof ParseCSV.parseCSV).toEqual("function");
});

test("csvParser works correctly - 1,2,3\n4,5,6", () => {
  expect(ParseCSV.parseCSV("1,2,3\n4,5,6")).toEqual([
    ["1", "2", "3"],
    ["4", "5", "6"],
  ]);
});

test('csvParser works correctly - 1,"two was here",3\n4,5,6', () => {
  expect(ParseCSV.parseCSV('1,"two was, here",3\n4,5,6')).toEqual([
    ["1", "two was, here", "3"],
    ["4", "5", "6"],
  ]);
});

test("csvParser works correctly - 1\t2\t3\n4\t5\t6", () => {
  expect(ParseCSV.parseCSV("1\t2\t3\n4\t5\t6", "\t")).toEqual([
    ["1", "2", "3"],
    ["4", "5", "6"],
  ]);
});

test('csvParser should throw error for unclosed quote - 1, 2, 3, "4, 5, 6, 7', () => {
  expect(() => ParseCSV.parseCSV('1, 2, 3, "4, 5, 6, 7')).toThrowError(
    "Unclosed Quotes!"
  );
});

test('csvParser works correctly - one,"two wraps\nonto ""two"" lines",three\n4,,6', () => {
  expect(
    ParseCSV.parseCSV('one,"two wraps\nonto ""two"" lines",three\n4,,6')
  ).toEqual([
    ["one", 'two wraps\nonto "two" lines', "three"],
    ["4", "", "6"],
  ]);
});

test('csvParser works correctly - 1,"",3\n4,5,6', () => {
  expect(ParseCSV.parseCSV('1,"",3\n4,5,6')).toEqual([
    ["1", "", "3"],
    ["4", "5", "6"],
  ]);
});
