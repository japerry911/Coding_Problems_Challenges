/*
---Find the First M Multiples of N---
Implement a function, multiples(m, n), which returns an array of the first m multiples of the real
number n. Assume that m is a positive integer.

Ex.

multiples(3, 5.0)
should return

[5.0, 10.0, 15.0]
 */

fn main() {
    println!("{:?}", multiples(3, 5.0));
}

fn multiples(m:i32, n:f64) -> Vec<f64> {
    let mut return_vector = Vec::new();
    let mut push_value = 0.0;

    for _ in 0..m {
        push_value += n;
        return_vector.push(push_value);
    }

    return return_vector;
}