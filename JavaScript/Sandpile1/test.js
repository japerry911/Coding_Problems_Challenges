const Sandpile = require("./index");

test("Sandpile is a class (function)", () => {
  expect(typeof Sandpile).toEqual("function");
});

test("Sandpile constructs correctly with no input", () => {
  expect(new Sandpile().piles).toEqual([
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0],
  ]);
});

test("Sandpile constructs correctly with normal input", () => {
  expect(new Sandpile("130\n121\n322").piles).toEqual([
    [1, 3, 0],
    [1, 2, 1],
    [3, 2, 2],
  ]);
});

test("topper works correctly in constructor", () => {
  expect(new Sandpile("130\n141\n322").piles).toEqual([
    [2, 0, 1],
    [2, 1, 2],
    [3, 3, 2],
  ]);
});

test("toString works correctly", () => {
  expect(new Sandpile("130\n121\n322").toString()).toEqual("130\n121\n322");
});

test("toString, constructor, and toppler work correctly", () => {
  expect(new Sandpile("130\n141\n322").toString()).toEqual("201\n212\n332");
});

test("Basic Add test", () => {
  let sp1 = new Sandpile("000\n000\n000");
  let sp2 = new Sandpile();
  expect(sp1.add(sp2).toString()).toEqual("000\n000\n000");
});

test("Complex Add test", () => {
  let sp1 = new Sandpile("111\n111\n111");
  let sp2 = new Sandpile("111\n111\n111");
  let sp3 = new Sandpile("010\n101\n100");
  expect(sp1.add(sp2).add(sp3).toString()).toEqual("232\n323\n322");
});

test("Custom toppler constructor test", () => {
  expect(new Sandpile("430\n121\n322").toString()).toEqual("101\n231\n322");
});

test("toppling test", () => {
  expect(new Sandpile("441\n531\n310").toString()).toEqual("322\n022\n130");
});

test("failed test test", () => {
  expect(new Sandpile("830\n131\n222").toString()).toEqual("221\n012\n332");
});
