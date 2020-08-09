const SimpleAssembler = require("./index");

test("simpleAssembler is a function", () => {
  expect(typeof SimpleAssembler).toEqual("function");
});

test("simpleAssembler works correctly", () => {
  expect(
    SimpleAssembler(["mov a 5", "inc a", "dec a", "dec a", "jnz a -1", "inc a"])
  ).toEqual({ a: 1 });
});

test("simpleAssembler works correctly", () => {
  expect(
    SimpleAssembler(["mov a -10", "mov b a", "inc a", "dec b", "jnz a -2"])
  ).toEqual({ a: 0, b: -20 });
});

test("simpleAssembler works correctly", () => {
  expect(
    SimpleAssembler([
      "mov d 100",
      "dec d",
      "mov b d",
      "jnz b -2",
      "inc d",
      "mov a d",
      "jnz 5 10",
      "mov c a",
    ])
  ).toEqual({ d: 1, b: 0, a: 1 });
});

test("simpleAssembler works correctly", () => {
  expect(
    SimpleAssembler([
      "mov w 30",
      "mov a 0",
      "jnz a 5",
      "jnz w 5",
      "dec w",
      "dec a",
      "dec w",
      "dec w",
      "dec a",
      "dec w",
      "dec w",
      "dec a",
    ])
  ).toEqual({ w: 28, a: -2 });
});

test("simpleAssembler works correctly", () => {
  expect(
    SimpleAssembler([
      "mov a 1",
      "mov b 1",
      "mov c 0",
      "mov d 26",
      "jnz c 2",
      "jnz 1 5",
      "mov c 7",
      "inc d",
      "dec c",
      "jnz c -2",
      "mov c a",
      "inc a",
      "dec b",
      "jnz b -2",
      "mov b c",
      "dec d",
      "jnz d -6",
      "mov c 18",
      "mov d 11",
      "inc a",
      "dec d",
      "jnz d -2",
      "dec c",
      "jnz c -5",
    ])
  ).toEqual({ a: 318009, b: 196418, c: 0, d: 0 });
});
