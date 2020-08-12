/*
---Double Cola---
Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola" drink vending
machine; there are no other people in the queue. The first one in the queue (Sheldon) buys a can,
drinks it and doubles! The resulting two Sheldons go to the end of the queue. Then the next in the
queue (Leonard) buys a can, drinks it and gets to the end of the queue as two Leonards, and so on.

For example, Penny drinks the third can of cola and the queue will look like this:

Rajesh, Howard, Sheldon, Sheldon, Leonard, Leonard, Penny, Penny
Write a program that will return the name of the person who will drink the n-th cola.

Input:
The input data consist of an array which contains at least 1 name, and single integer n which may
go as high as the biggest number your language of choice supports (if there's such limit, of
course).

Output / Examples:
Return the single line — the name of the person who drinks the n-th can of cola. The cans are
numbered starting from 1.

let names = &[Name::Sheldon, Name::Leonard, Name::Penny, Name::Rajesh, Name::Howard];
assert_eq!(who_is_next(names, 1), Name::Sheldon);
assert_eq!(who_is_next(names, 6), Name::Sheldon);
assert_eq!(who_is_next(names, 52), Name::Penny);
assert_eq!(who_is_next(names, 7230702951), Name::Leonard);
 */

use std::thread::current;

fn main() {
    println!("{:?}", who_is_next(&vec![
        Name::Sheldon,
        Name::Leonard,
        Name::Penny,
        Name::Rajesh,
        Name::Howard,
    ], 7_230_702_951));
    println!("{:?}", who_is_next(&vec![
        Name::Sheldon,
        Name::Leonard,
        Name::Penny,
        Name::Rajesh,
        Name::Howard],
    10));
    println!("{:?}", who_is_next(&vec![
        Name::Rajesh,
        Name::Sheldon,
        Name::Leonard,
        Name::Sheldon,
        Name::Penny,
        Name::Howard], 4202546056496772934));
    println!("{:?}", who_is_next(&vec![
        Name::Penny,
        Name::Rajesh,
        Name::Howard,
        Name::Sheldon,
        Name::Sheldon,
        Name::Sheldon,
        Name::Howard,
        Name::Penny,
        Name::Howard,
        Name::Penny,
        Name::Howard,
        Name::Leonard,
        Name::Rajesh,
        Name::Leonard], 25586));
}

#[derive(Debug, Eq, PartialEq, Copy, Clone)]
enum Name { Sheldon, Leonard, Penny, Rajesh, Howard }

type Names = Vec<Name>;

fn who_is_next(names: &Names, n: usize) -> Name {
    if n < names.len() {
        return names[n - 1];
    }

    let mut index_count:f64 = names.len() as f64;
    let mut current_iteration:f64 = 1.0;
    let two:f64 = 2.0;

    loop {
        index_count += two.powf(current_iteration) * names.len() as f64;
        if index_count >= n as f64 {
            break;
        }
        current_iteration += 1.0;
    }

    index_count -= two.powf(current_iteration) * names.len() as f64;

    let repeats:f64 = two.powf(current_iteration);
    let something:f64 = n as f64 - index_count - 1.0;
    let final_index:usize = (something / repeats) as usize;

    names[final_index]

    // Brute Force - Too Slow
    /*let mut cola_queue = names.clone();
    let mut counter = 0;

    while cola_queue.len() < n {
        let push_name = cola_queue[counter];
        cola_queue.push(push_name);
        cola_queue.push(push_name);
        counter += 1;
    }

    cola_queue[n - 1]*/
}
