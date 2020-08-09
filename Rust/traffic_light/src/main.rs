fn main() {
    println!("{}", update_light("green"));
}

fn update_light(current:&str) -> String {
    match current {
        "green" => "yellow".to_string(),
        "yellow" => "red".to_string(),
        "red" => "green".to_string(),
        _ => "BROKEN".to_string()
    }
}
