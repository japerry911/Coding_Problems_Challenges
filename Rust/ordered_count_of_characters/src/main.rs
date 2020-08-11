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
    // Solution 2
    sip.chars().fold(Vec::new(), |mut accumlator:Vec<(char, i32)>, cv| {
        match accumlator.iter().position(|&t| t.0 == cv) {
            Some(x) => accumlator[x].1 += 1,
            None => accumlator.push((cv, 1))
        };
        accumlator
    })


    // Solution 1
    /*let mut return_vec:Vec<(char, i32)> = Vec::new();

    for c in sip.chars() {
        let position = return_vec.iter().position(|&t| t.0 == c);
        if position.is_none() {
            return_vec.push((c, 1));
        } else {
            return_vec[position.unwrap()].1 += 1;
        }
    }

    return return_vec;*/
}
