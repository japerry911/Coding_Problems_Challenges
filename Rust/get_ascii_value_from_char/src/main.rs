/*
Write a function which takes a number and returns the corresponding ASCII char for that value.

Example:

get_char(65) # => 'A'
For ASCII table, you can refer to http://www.asciitable.com/
 */

fn main() {
    println!("{}", get_char(55));
}

fn get_char(c:i32) -> char {
    let u8:u8 = c as u8;
    return u8 as char;
}
