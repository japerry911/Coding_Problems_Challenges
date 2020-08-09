const Maskify = require("./index");

test("Maskify is a function", () => {
  expect(typeof Maskify).toEqual("function");
});

test("Maskify works correctly - 1", () => {
  expect(Maskify("4556364607935616")).toEqual("############5616");
});

test("Maskify works correctly - 2", () => {
  expect(Maskify("1")).toEqual("1");
});

test("Maskify works correctly - 2", () => {
  expect(Maskify("Nananananananananananananananana Batman!")).toEqual(
    "####################################man!"
  );
});
