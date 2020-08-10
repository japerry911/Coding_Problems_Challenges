/*
---The Meeting---
John has invited some friends. His list is:

s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;
Alfred:Corwill";
Could you make a program that

makes this string uppercase
gives it sorted in alphabetical order by last name.
When the last names are the same, sort them by first name. Last name and first name of a guest come
in the result between parentheses separated by a comma.

So the result of function meeting(s) will be:

"(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)
(TORNBULL, BETTY)(TORNBULL, BJON)"
It can happen that in two distinct families with the same family name two people have the same
first name too.

Notes
You can see another examples in the "Sample tests".
 */

fn main() {
    println!("{}", meeting("Alissa:Cornwell;Sarah:Bell;Andrew:Dorries;Ann:Kern;\
                              Haley:Arno;Paul:Dorny;Madison:Kern;Alex:Arno"));
}

fn meeting(s:&str) -> String {
    let mut return_string = String::new();

    let uppercase_split_s = s.to_uppercase();
    let mut vec:Vec<Vec<&str>> = uppercase_split_s.split(";").map(|ele| {
        ele.split(":").collect()})
        .collect();

    vec.sort_by(|a, b| {
        return if a[1].eq(b[1]) {
            a[0].cmp(&b[0])
        } else {
            a[1].cmp(&b[1])
        }
    });

    for (index, name) in vec.iter().enumerate() {
        return_string.push('(');
        return_string.push_str(name[1]);
        return_string.push_str(&", ".to_string());
        return_string.push_str(name[0]);
        return_string.push(')');
    }

    return_string
}