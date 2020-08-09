/*
---Build a Square---
I will give you an integer. Give me back a shape that is as long and wide as the integer. The
integer will be a whole number between 1 and 50.

Example
n = 3, so I expect a 3x3 square back just like below as a string:

+++
+++
+++
 */

fn main() {
    println!("{}", generate_shape(3));
}

fn generate_shape(n:i32) -> String {
    return "".to_string();
}
