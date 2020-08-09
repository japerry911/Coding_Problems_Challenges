/*
---Growth of a Population---
In a small town the population is p0 = 1000 at the beginning of a year. The population regularly
increases by 2 percent per year and moreover 50 new inhabitants per year come to live in the town.
How many years does the town need to see its population greater or equal to p = 1200 inhabitants?

At the end of the first year there will be:
1000 + 1000 * 0.02 + 50 => 1070 inhabitants

At the end of the 2nd year there will be:
1070 + 1070 * 0.02 + 50 => 1141 inhabitants (number of inhabitants is an integer)

At the end of the 3rd year there will be:
1141 + 1141 * 0.02 + 50 => 1213

It will need 3 entire years.
More generally given parameters:

p0, percent, aug (inhabitants coming or leaving each year), p (population to surpass)

the function nb_year should return n number of entire years needed to get a population greater or
equal to p.

aug is an integer, percent a positive or null number, p0 and p are positive integers (> 0)

Examples:
nb_year(1500, 5, 100, 5000) -> 15
nb_year(1500000, 2.5, 10000, 2000000) -> 10
Note: Don't forget to convert the percent parameter as a percentage in the body of your function:
if the parameter percent is 2 you have to convert it to 0.02.
 */

fn main() {
    println!("15 = {}", nb_year(1500, 5.0, 100, 5000));
    println!("10 = {}", nb_year(1500000, 2.5, 10000, 2000000));
    println!("484 = {}", nb_year(273005, 0.1, 1365, 1289385));
}

fn nb_year(p0:i32, percent:f64, aug:i32, p:i32) -> i32 {
    let mut current_population:f64 = p0 as f64;
    let mut years = 0;
    let percent_adjusted = percent / 100.0;

    while (current_population).floor() < p as f64 {
        current_population += (current_population * percent_adjusted).floor();
        current_population += aug as f64;
        years += 1;
    }

    years
}
