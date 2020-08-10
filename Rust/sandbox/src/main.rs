use regex::Regex;

fn main() {
    /*let a = [1, 2, 3];
    println!("{:?}", a);
    let doubled:Vec<i32> = a.iter().map(|&x| x * 2).collect();
    println!("{:?}", doubled);*/

    let re_test = Regex::new("^[a-zA-Z]+$").unwrap();
    let test_pass1 = "aVEASCasd";
    let test_fail1 = "aVEASCas3d";
    println!("Passed -> {}", re_test.is_match(test_pass1));
    println!("Failed -> {}", !re_test.is_match(test_fail1));

    let re = Regex::new(r"(\d{4})-(\d{2})-(\d{2})").unwrap();
    let text = "2012-03-14, 2013-01-01 and 2014-07-05";
    for cap in re.captures_iter(text) {
        println!("Month: {} Day: {} Year: {}", &cap[2], &cap[3], &cap[1]);
    }
}
