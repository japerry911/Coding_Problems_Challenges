/*
---Bit Counting---
Write a function that takes an integer as input, and returns the number of bits that are equal to
one in the binary representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this
case
 */

fn main() {
    println!("2 = {}", count_bits(10));
    println!("5 = {}", count_bits(1234));
}

fn count_bits(n:i64) -> u32 {
    let mut current_power_of_two:i64 = 1;
    let mut number_of_bits:u32 = 0;
    let mut mut_n:i64 = n;

    while current_power_of_two <= n {
        current_power_of_two *= 2;
    }
    current_power_of_two /= 2;

    while mut_n > 0 {
        if current_power_of_two <= mut_n {
            mut_n -= current_power_of_two;
            number_of_bits += 1;
        }

        current_power_of_two /= 2;
    }

    number_of_bits
}
