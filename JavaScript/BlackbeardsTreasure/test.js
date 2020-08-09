const treasureCode = require("./index");

test("treasureCode is a function", () => {
  expect(typeof treasureCode).toEqual("function");
});

test("treasureCode works correctly - A2B1", () => {
  expect(treasureCode("A2B1")).toEqual("A2B1");
});

test("treasureCode works correctly - A112B333C4", () => {
  expect(treasureCode("A112B333C4")).toEqual("A112B333C4");
});

test("treasureCode works correctly - R2D2C4", () => {
  expect(treasureCode("R2D2C4")).toEqual("R1D1C2");
});

test("treasureCode works correctly - R2D2C4", () => {
  expect(treasureCode("R2D2C4")).toEqual("R1D1C2");
});

test("treasureCode works correctly - T3Y3U9E6", () => {
  expect(treasureCode("T3Y3U9E6")).toEqual("T1Y1U3E2");
});

test("treasureCode works correctly - M3H7", () => {
  expect(treasureCode("M3H7")).toEqual("M3H7");
});

test("treasureCode works correctly - Y14U7I7P21", () => {
  expect(treasureCode("Y14U7I7P21")).toEqual("Y2U1I1P3");
});

test("treasureCode works correctly - Z4Y12X8", () => {
  expect(treasureCode("Z4Y12X8")).toEqual("Z1Y3X2");
});

test("treasureCode works correctly - Z18Y12", () => {
  expect(treasureCode("Z18Y12")).toEqual("Z3Y2");
});

test("treasureCode works correctly - D6597A7654X6262U2680D758R9310G8482", () => {
  expect(treasureCode("D6597A7654X6262U2680D758R9310G8482")).toEqual(
    "D6597A7654X6262U2680D758R9310G8482"
  );
});
