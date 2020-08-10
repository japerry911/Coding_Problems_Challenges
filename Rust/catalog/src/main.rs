use regex::Regex;

fn main() {
    println!("ladder > prx: $112 qty: 12 = {}", catalog(&s(), "ladder"));
    println!("{}",
             catalog(&s(), "saw"));
    println!("{}", catalog(&s(), "bazooka"));
}

fn catalog(s: &str, article: &str) -> String {
    let re = Regex::new(r"^<prod><name>([A-Za-z\d\s]+)</name>(<prx>[0-9]+(\.[0-9]+)?)</prx>(<qty>[0-9]+</qty>)</prod>$").unwrap();
    let split_s = s.split("\n\n").into_iter();
    let mut fetched_items:Vec<&str> = Vec::new();

    for line_item in split_s {
        let regex_result = re.captures_iter(&line_item);
        for cap in regex_result {
            let match_result = match &cap.get(1) {
                Some(x) => {
                    if x.as_str().contains(&article) || x.as_str() == article {
                        Some(line_item)
                    } else {
                        None
                    }
                },
                _ => None
            };

            if match_result.is_some() {
                fetched_items.push(match_result.unwrap());
            }
        }
    }

    let mut return_string = String::new();
    let fetched_length = fetched_items.len();

    if fetched_length == 0 {
        return "Nothing".to_string();
    }

    for (index, item) in fetched_items.into_iter().enumerate() {
        let mut cleaned_up_item = item
            .replace("<prod>", "")
            .replace("<name>", "")
            .replace("</name>", " > ")
            .replace("<prx>", "prx: $")
            .replace("</prx>", " qty: ")
            .replace("<qty>","")
            .replace("</qty>", "")
            .replace("</prod>", "");

        if index < fetched_length - 1 {
            cleaned_up_item.push('\n');
        }

        return_string.push_str(cleaned_up_item.as_str());
    }

    return_string
}

fn s() -> String {
    let a: Vec<&str> = vec!["<prod><name>drill</name><prx>99</prx><qty>5</qty></prod>",
                            "<prod><name>hammer</name><prx>10</prx><qty>50</qty></prod>",
                            "<prod><name>screwdriver</name><prx>5</prx><qty>51</qty></prod>",
                            "<prod><name>table saw</name><prx>1099.99</prx><qty>5</qty></prod>",
                            "<prod><name>saw</name><prx>9</prx><qty>10</qty></prod>",
                            "<prod><name>chair</name><prx>100</prx><qty>20</qty></prod>",
                            "<prod><name>fan</name><prx>50</prx><qty>8</qty></prod>",
                            "<prod><name>wire</name><prx>10.8</prx><qty>15</qty></prod>",
                            "<prod><name>battery</name><prx>150</prx><qty>12</qty></prod>",
                            "<prod><name>pallet</name><prx>10</prx><qty>50</qty></prod>",
                            "<prod><name>wheel</name><prx>8.80</prx><qty>32</qty></prod>",
                            "<prod><name>extractor</name><prx>105</prx><qty>17</qty></prod>",
                            "<prod><name>bumper</name><prx>150</prx><qty>3</qty></prod>",
                            "<prod><name>ladder</name><prx>112</prx><qty>12</qty></prod>",
                            "<prod><name>hoist</name><prx>13.80</prx><qty>32</qty></prod>",
                            "<prod><name>platform</name><prx>65</prx><qty>21</qty></prod>",
                            "<prod><name>car wheel</name><prx>505</prx><qty>7</qty></prod>",
                            "<prod><name>bicycle wheel</name><prx>150</prx><qty>11</qty></prod>",
                            "<prod><name>big hammer</name><prx>18</prx><qty>12</qty></prod>",
                            "<prod><name>saw for metal</name><prx>13.80</prx><qty>32</qty></prod>",
                            "<prod><name>wood pallet</name><prx>65</prx><qty>21</qty></prod>",
                            "<prod><name>circular fan</name><prx>80</prx><qty>8</qty></prod>",
                            "<prod><name>exhaust fan</name><prx>62</prx><qty>8</qty></prod>",
                            "<prod><name>window fan</name><prx>62</prx><qty>8</qty></prod>"];
    return a.join("\n\n");
}