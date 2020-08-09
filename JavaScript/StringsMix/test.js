const mix = require("./index");

test("mix is a function", () => {
  expect(typeof mix).toEqual("function");
});

test("mix works properly - Test 1", () => {
  expect(mix("Are they here", "yes, they are here")).toEqual(
    "2:eeeee/2:yy/=:hh/=:rr"
  );
});

test("mix works correctly - Test 2", () => {
  expect(
    mix("looping is fun but dangerous", "less dangerous than coding")
  ).toEqual("1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg");
});

test("mix works properly - Test 3", () => {
  expect(mix(" In many languages", " there's a pair of functions")).toEqual(
    "1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt"
  );
});

test("mix works correctly - Test 4", () => {
  expect(mix("Lords of the Fallen", "gamekult")).toEqual("1:ee/1:ll/1:oo");
});

test("mix works correctly - Test 5", () => {
  expect(mix("codewars", "codewars")).toEqual("");
});

test("mix works correctly - Test 6", () => {
  expect(mix("A generation must confront the looming ", "codewarrs")).toEqual(
    "1:nnnnn/1:ooooo/1:tttt/1:eee/1:gg/1:ii/1:mm/=:rr"
  );
});

test("mix works correctly - Test 7", () => {
  expect(
    mix("@zrtg7ordbGkeezNemwkCuxxq:yqxa", ":qvxr(axmd:plagNbagg7lykyVqaos")
  ).toEqual("2:aaaa/1:eee/1:xxx/2:ggg/1:kk/1:rr/1:zz/2:ll/2:yy/=:qq");
});
