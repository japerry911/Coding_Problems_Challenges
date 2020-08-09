const Spiral = require("./index");

test("encode is a function", () => {
  expect(typeof Spiral.encode).toEqual("function");
});

test("decode is a function", () => {
  expect(typeof Spiral.decode).toEqual("function");
});

test("encode works correctly - Romani ite domum", () => {
  expect(Spiral.encode("Romani ite domum")).toEqual("Rntodomiimuea  m");
});

test("encode works correctly - Sic transit gloria mundi", () => {
  expect(Spiral.encode("Sic transit gloria mundi")).toEqual(
    "Stsgiriuar i ninmd l otac"
  );
});

test("decode works correctly - Rntodomiimuea  m", () => {
  expect(Spiral.decode("Rntodomiimuea  m")).toEqual("Romani ite domum");
});

test("decode works correctly - Stsgiriuar i ninmd l otac", () => {
  expect(Spiral.decode("Stsgiriuar i ninmd l otac")).toEqual(
    "Sic transit gloria mundi"
  );
});
