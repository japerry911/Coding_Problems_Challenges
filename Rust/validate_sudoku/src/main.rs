/*
---Sudoku Validator---
Given a Sudoku data structure with size NxN, N > 0 and √N == integer, write a method to validate if it has been filled out correctly.

The data structure is a multi-dimensional Array, i.e:

[
  [7,8,4,  1,5,9,  3,2,6],
  [5,3,9,  6,7,2,  8,4,1],
  [6,1,2,  4,3,8,  7,5,9],

  [9,2,8,  7,1,5,  4,6,3],
  [3,5,7,  8,4,6,  1,9,2],
  [4,6,1,  9,2,3,  5,8,7],

  [8,7,6,  3,9,4,  2,1,5],
  [2,4,3,  5,6,1,  9,7,8],
  [1,9,5,  2,8,7,  6,3,4]
]
Rules for validation

Data structure dimension: NxN where N > 0 and √N == integer
Rows may only contain integers: 1..N (N included)
Columns may only contain integers: 1..N (N included)
'Little squares' (3x3 in example above) may also only contain integers: 1..N (N included)
*/

use std::collections::HashMap;

fn main() {
    let sud1 = Sudoku{data: vec![
        vec![7,8,4, 1,5,9, 3,2,6],
        vec![5,3,9, 6,7,2, 8,4,1],
        vec![6,1,2, 4,3,8, 7,5,9],

        vec![9,2,8, 7,1,5, 4,6,3],
        vec![3,5,7, 8,4,6, 1,9,2],
        vec![4,6,1, 9,2,3, 5,8,7],

        vec![8,7,6, 3,9,4, 2,1,5],
        vec![2,4,3, 5,6,1, 9,7,8],
        vec![1,9,5, 2,8,7, 6,3,4]
    ]};
    println!("{}", sud1.is_valid());
}

struct Sudoku {
    data: Vec<Vec<u32>>
}

impl Sudoku {
    fn is_valid(&self) -> bool {
        let mut key:Vec<u32> = Vec::new();
        for i in 1..=self.data.len() {
            key.push(i as u32);
        }

        let mut column_map:HashMap<usize, Vec<u32>> = HashMap::new();
        let mut box_row_counter:usize = 0;
        let mut box_hash:HashMap<usize, Vec<u32>> = HashMap::new();
        let box_size = (self.data.len() as f64).sqrt() as usize;

        for (r_index, r) in self.data.iter().enumerate() {
            let mut box_counter:usize = 0;
            let mut box_number:usize = 0;
            let mut r_copy = r.clone();

            box_row_counter += 1;
            r_copy.sort();

            if r_copy.ne(&key) {
                return false;
            }
            for c in r {
                column_map.entry(r_index).or_insert(Vec::new()).push(*c);
                box_hash.entry(box_number).or_insert(Vec::new()).push(*c);

                box_counter += 1;
                if box_counter >= box_size {
                    box_counter = 0;
                    box_number += 1;
                }
            }

            if box_row_counter >= box_size {
                for pair in &box_hash {
                    let mut vec_copy = pair.1.clone();
                    vec_copy.sort();
                    if vec_copy.ne(&key) {
                        return false;
                    }
                }
                box_hash.clear();
                box_row_counter = 0;
            }
        }

        for mut pair in column_map {
            pair.1.sort();
            if pair.1.ne(&key) {
                return false;
            }
        }

        true
    }
}
