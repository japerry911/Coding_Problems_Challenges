/*
---String Letter Counting---
Take an input string and return a string that is made up of the number of occurences of each
english letter in the input followed by that letter, sorted alphabetically. The output string
shouldn't contain chars missing from input (chars with 0 occurence); leave them out.

An empty string, or one with no letters, should return an empty string.

Notes:

the input will always be valid;
treat letters as case-insensitive
Examples
"This is a test sentence."  ==>  "1a1c4e1h2i2n4s4t"
""                          ==>  ""
"555"                       ==>  ""
 */

fn main() {
    println!("{}", string_letter_count(&"The quick brown fox jumps over the lazy dog."));
}

fn string_letter_count(s:&str) -> String {
    return "".to_string();
}