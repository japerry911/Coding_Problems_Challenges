/*
---Ordered Count of Characters---
Count the number of occurrences of each character and return it as a list of tuples in order of
appearance. For empty output return an empty list.

Example:

ordered_count("abracadabra") == vec![('a', 5), ('b', 2), ('r', 2), ('c', 1), ('d', 1)]
 */

fn main() {
    println!("[('a', 5), ('b', 2), ('r', 2), ('c', 1), ('d', 1)] = {:?}",
             ordered_count("abracadabra"));
    println!("[('b', 1), ('a', 3), ('n', 2)] = {:?}", ordered_count("banana"));
}

fn ordered_count(sip: &str) -> Vec<(char, i32)> {
    return vec![];
}
