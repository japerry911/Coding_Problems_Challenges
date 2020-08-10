/*
Given a string with friends to visit in different states:

ad3="John Daggett, 341 King Road, Plymouth MA
Alice Ford, 22 East Broadway, Richmond VA
Sal Carpenter, 73 6th Street, Boston MA"
we want to produce a result that sorts the names by state and lists the name of the state followed
by the name of each person residing in that state (people's names sorted). When the result is
printed we get:

Massachusetts
.....^John Daggett 341 King Road Plymouth Massachusetts
.....^Sal Carpenter 73 6th Street Boston Massachusetts
^Virginia
.....^Alice Ford 22 East Broadway Richmond Virginia
Spaces not being always well seen, in the above result ^ means a white space.

The resulting string (when not printed) will be:

"Massachusetts\n..... John Daggett 341 King Road Plymouth Massachusetts\n..... Sal Carpenter 73 6th
Street Boston Massachusetts\n Virginia\n..... Alice Ford 22 East Broadway Richmond Virginia"
or (the separator is \n or \r\n depending on the language)

"Massachusetts\r\n..... John Daggett 341 King Road Plymouth Massachusetts\r\n..... Sal Carpenter 73
6th Street Boston Massachusetts\r\n Virginia\r\n..... Alice Ford 22 East Broadway Richmond Virginia"
Notes
There can be a blank last line in the given string of addresses.
The tests only contains CA, MA, OK, PA, VA, AZ, ID, IN for states.
You can see another example in the "Sample tests".
States
For the lazy ones:

'AZ': 'Arizona',
'CA': 'California',
'ID': 'Idaho',
'IN': 'Indiana',
'MA': 'Massachusetts',
'OK': 'Oklahoma',
'PA': 'Pennsylvania',
'VA': 'Virginia'
 */

use std::collections::BTreeMap;

fn main() {
    let input1:&str = "Alice Ford, 22 East Broadway, Richmond VA\nSal Carpenter, 73 6th Street, \
                        Boston MA\nJohn Daggett, 341 King Road, Plymouth MA";
    println!("{}", by_state(input1));
}
fn by_state(str:&str) -> String {
    let state_map:BTreeMap<String, String> = [("AZ", "Arizona"), ("CA", "California"),
        ("ID", "Idaho"), ("IN", "Indiana"), ("MA", "Massachusetts"), ("OK", "Oklahoma"),
        ("PA", "Pennsylvania"), ("VA", "Virginia")]
        .iter()
        .map(|x| (x.0.to_string(), x.1.to_string()))
        .collect();
    let mut return_string = String::new();
    let input_vec:Vec<String> = str.split('\n').map(|x| x.to_string()).collect();
    let mut holding_map:BTreeMap<String, Vec<String>> = BTreeMap::new();

    for i in input_vec {
        if i == "\n" {
            continue;
        }

        let mut state_vec:Vec<char> = i.chars().rev().take(2).collect();
        state_vec.reverse();
        let abbreviation:String = state_vec.into_iter().collect();
        let state:String = state_map.get(abbreviation.as_str()).unwrap().to_string();
        let updated_i = i.replace(&abbreviation, &state).replace(",", "");

        holding_map.entry(state).or_insert(vec![]).push(updated_i);
    }

    let mut index_counter = 0;
    let map_len = holding_map.len();
    for mut pair in holding_map {
        return_string.push_str(&pair.0);
        pair.1.sort();

        for address in pair.1 {
            return_string.push_str("\n..... ");
            return_string.push_str(&address);
        }

        if index_counter < map_len - 1 {
            return_string.push_str("\n ");
        }
        index_counter += 1;
    }

    return_string
}
