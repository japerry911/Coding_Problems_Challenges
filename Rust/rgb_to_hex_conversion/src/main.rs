/*
---RGB to Hex Conversion---
The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a
hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values
that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

kata.rgb(255, 255, 255) -- returns FFFFFF
kata.rgb(255, 255, 300) -- returns FFFFFF
kata.rgb(0, 0, 0) -- returns 000000
kata.rgb(148, 0, 211) -- returns 9400D3
 */

fn main() {
    println!("010203 = {}", rgb(1, 2, 3));
    println!("FFFFFF = {}", rgb(255, 255, 255));
    println!("FEFDFC = {}", rgb(254, 253, 252));
    println!("00FF7D = {}", rgb(-20, 275, 125));
    println!("000000 = {}", rgb(0, 0, 0));
}

fn rgb(r:i32, g:i32, b:i32) -> String {
    "not done".to_string()
}