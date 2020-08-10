/*
---Adding Words - Part 1---
Add two English words together!

Implement a class Arith (struct struct Arith{value : &'static str,} in Rust) such that

  //javascript
  var k = new Arith("three");
  k.add("seven"); //this should return "ten"
  //c++
  Arith* k = new Arith("three");
  k->add("seven"); //this should return string "ten"
  //Rust
  let c = Arith{value: "three"};
  c.add("seven") // this should return &str "ten"
Input - Will be between zero and ten and will always be in lower case

Output - Word representation of the result of the addition. Should be in lower case
 */

use std::collections::HashMap;

fn main() {
    let test = Arith{ value: "three" };
    println!("ten = {:?}", test.add("seven"));
    println!("eleven = {:?}", test.add("eight"));
    println!("three = {:?}", test.add("zero"));
}

#[derive(Copy, Clone)]
struct Arith {
    value: &'static str
}

impl Arith {
    fn add(self, value2:&'static str) -> &str {
        let number_map:HashMap<&str, i32> = [("one", 1), ("two", 2), ("three", 3), ("four", 4),
            ("five", 5), ("six", 6), ("seven", 7), ("eight", 8), ("nine", 9), ("ten", 10),
            ("eleven", 11), ("twelve", 12), ("thirteen", 13), ("fourteen", 14), ("fifteen", 15),
            ("sixteen", 16), ("seventeen", 17), ("eighteen", 18), ("nineteen", 19), ("twenty", 20),
            ("zero", 0)].iter().cloned().collect();

        let result = number_map.get(self.value).unwrap() +
            number_map.get(value2).unwrap();

        number_map.iter().find_map(|(key, &val)|
            if val == result { Some(key) } else { None }).unwrap()
    }
}
