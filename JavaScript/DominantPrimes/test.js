const DominantPrimes = require("./index");

test("solve is a function", () => {
  expect(typeof DominantPrimes.solve).toEqual("function");
});

test("generatePrimes is a function", () => {
  expect(typeof DominantPrimes.generatePrimes).toEqual("function");
});

test("solve works correctly - 1", () => {
  expect(DominantPrimes.solve(0, 10)).toEqual(8);
});

test("solve works correctly - 2", () => {
  expect(DominantPrimes.solve(2, 200)).toEqual(1080);
});

test("solve works correctly - 3", () => {
  expect(DominantPrimes.solve(200, 2000)).toEqual(48132);
});

test("solve works correctly - 4", () => {
  expect(DominantPrimes.solve(500, 10000)).toEqual(847039);
});

test("solve works correctly - 5", () => {
  expect(DominantPrimes.solve(4000, 450000)).toEqual(806250440);
});
