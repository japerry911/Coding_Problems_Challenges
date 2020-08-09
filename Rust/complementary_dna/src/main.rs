/*
---Complimentary DNA---
Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the
"instructions" for the development and functioning of living organisms.

If you want to know more http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You have
function with one side of the DNA (string, except for Haskell); you need to get the other
complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here http://rosalind.info/problems/list-view/ (source)

dna_strand("ATTGC") // returns "TAACG"
dna_strand("GTAT")  // returns "CATA"
 */

fn main() {
    println!("{}", dna_strand("GTAT")); // CATA
}

fn dna_strand(dna:&str) -> String {
    let mut adjusted_dna = String::new();

    for c in dna.chars() {
        if c == 'A' {
            adjusted_dna.push('T');
        } else if c == 'T' {
            adjusted_dna.push('A');
        } else if c == 'C' {
            adjusted_dna.push('G');
        } else if c == 'G' {
            adjusted_dna.push('C');
        } else {let mut adjusted_dna = String::new();

            for c in dna.chars() {
                if c == 'A' {
                    adjusted_dna.push('T');
                } else if c == 'T' {
                    adjusted_dna.push('A');
                } else if c == 'C' {
                    adjusted_dna.push('G');
                } else if c == 'G' {
                    adjusted_dna.push('C');
                } else {
                    adjusted_dna.push(c);
                }
            }

            return adjusted_dna;
            adjusted_dna.push(c);
        }
    }

    return adjusted_dna;
}
