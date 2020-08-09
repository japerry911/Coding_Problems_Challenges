const WeightForWeight = require("./index");

test("orderWeight is a function", () => {
  expect(typeof WeightForWeight.orderWeight).toEqual("function");
});

test("sumUpDigits test - 1", () => {
  expect(WeightForWeight.sumUpDigits("123")).toEqual(6);
});

test("sumUpDigits test - 2", () => {
  expect(WeightForWeight.sumUpDigits("8219")).toEqual(20);
});

test("orderWeight sorts the list correctly - 1", () => {
  expect(WeightForWeight.orderWeight("56 65 74 100 99 68 86 180 90")).toEqual(
    "100 180 90 56 65 74 68 86 99"
  );
});

test("orderWeight sorts the list correctly - 2", () => {
  expect(WeightForWeight.orderWeight("103 123 4444 99 2000")).toEqual(
    "2000 103 123 4444 99"
  );
});

test("orderWeight sorts the list correctly - 3", () => {
  expect(
    WeightForWeight.orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123")
  ).toEqual("11 11 2000 10003 22 123 1234000 44444444 9999");
});
