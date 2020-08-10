/*
---Steps in Prime---
The prime numbers are not regularly spaced. For example from 2 to 3 the step is 1. From 3 to 5 the
step is 2. From 7 to 11 it is 4. Between 2 and 50 we have the following pairs of 2-steps primes:

3, 5 - 5, 7, - 11, 13, - 17, 19, - 29, 31, - 41, 43

We will write a function step with parameters:

g (integer >= 2) which indicates the step we are looking for,

m (integer >= 2) which gives the start of the search (m inclusive),

n (integer >= m) which gives the end of the search (n inclusive)

In the example above step(2, 2, 50) will return [3, 5] which is the first pair between 2 and 50
with a 2-steps.

So this function should return the first pair of the two prime numbers spaced with a step of g
between the limits m, n if these g-steps prime numbers exist otherwise nil or null or None or
Nothing or [] or "0, 0" or {0, 0} or 0 0(depending on the language).

#Examples:

step(2, 5, 7) --> [5, 7] or (5, 7) or {5, 7} or "5 7"

step(2, 5, 5) --> nil or ... or [] in Ocaml or {0, 0} in C++

step(4, 130, 200) --> [163, 167] or (163, 167) or {163, 167}

See more examples for your language in "RUN"
Remarks:
([193, 197] is also such a 4-steps primes between 130 and 200 but it's not the first pair).

step(6, 100, 110) --> [101, 107] though there is a prime between 101 and 107 which is 103; the
pair 101-103 is a 2-step.

#Notes: The idea of "step" is close to that of "gap" but it is not exactly the same. For those
interested they can have a look at http://mathworld.wolfram.com/PrimeGaps.html.

A "gap" is more restrictive: there must be no primes in between (101-107 is a "step" but not a
"gap". Next kata will be about "gaps":-).

For Go: nil slice is expected when there are no step between m and n. Example: step(2,4900,4919) --> nil
 */

fn main() {
    println!("(101, 103) = {:?}", step(2,100,110));
    println!("(103, 107) = {:?}", step(4,100,110));
    println!("(30089, 30097) = {:?}", step(8,30000,100000));
    println!("(1321, 1373) = {:?}", step(52, 1300, 15000));
    println!("(10000139, 10000141) = {:?}", step(2,10000000,11000000));
}

fn step(g: i32, m: u64, n: u64) -> Option<(u64, u64)> {
    for i in m..(n - (g as u64)) {
        if is_prime(i) && is_prime(i + (g as u64)) {
            return Some((i, i + (g as u64)));
        }
    }
    None
}

fn is_prime(x: u64) -> bool {
    if x == 2 {
        return true;
    } else if x < 3 || (x % 2 == 0) || (x % 5 == 0) {
        return false;
    }
    let limit:u64 = (x as f64).sqrt() as u64;
    for i in 3..=limit {
        if x % i == 0 {
            return false;
        }
    }
    true
}

// Too Slow
/*fn step(g: i32, m: u64, n: u64) -> Option<(u64, u64)> {
    let primes:Vec<u64> = generate_primes(m, n);
    let mut seeking_primes = HashSet::new();

    for prime in &primes {
        let current_search:u64 = *prime - (g as u64);

        let result = seeking_primes.contains(&current_search);
        if result {
            return Some((current_search, *prime));
        }

        seeking_primes.insert(prime);
    }

    None
}

fn generate_primes(start: u64, end: u64) -> Vec<u64> {
    let mut prime_vec:Vec<u64> = Vec::new();
    let limit = (end as f64).sqrt() as u64;
    let mut bool_vec:Vec<bool> = Vec::new();
    for _ in 0..end {
        bool_vec.push(true);
    }
    for i in 2..=limit {
        if bool_vec[i as usize] {
            for x in ((i * i)..end).step_by(i as usize) {
                bool_vec[x as usize] = false;
            }
        }
    }
    for i in start..end {
        if bool_vec[i as usize] {
            prime_vec.push(i);
        }
    }

    prime_vec
}*/