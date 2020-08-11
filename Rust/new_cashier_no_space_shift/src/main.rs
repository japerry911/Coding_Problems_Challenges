/*
---New Cashier No Space or Shift---
Some new cashiers started to work at your restaurant.

They are good at taking orders, but they don't know how to capitalize words, or use a space bar!

All the orders they create look something like this:

"milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"

The kitchen staff are threatening to quit, because of how difficult it is to read the orders.

Their preference is to get the orders as a nice clean string with spaces and capitals like so:

"Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"

The kitchen staff expect the items to be in the same order as they appear in the menu.

The menu items are fairly simple, there is no overlap in the names of the items:

1. Burger
2. Fries
3. Chicken
4. Pizza
5. Sandwich
6. Onionrings
7. Milkshake
8. Coke
 */

fn main() {
    println!("{}", get_order("milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"
                 .to_string()));
}

fn get_order(input: String) -> String {
    let items: Vec<&str> = vec!["Burger ", "Fries ", "Chicken ", "Pizza ", "Sandwich ",
                                "Onionrings ", "Milkshake ", "Coke "];
    let mut return_string:String = String::new();
    for item in items {
        for _ in 0..input.matches(&item.to_lowercase().trim_end()).count() {
            return_string.push_str(item);
        }
    }

    return_string.trim_end().to_string()

    /*let master_vec:Vec<(String, String)> = [("burger", "Burger "), ("fries", "Fries "),
        ("chicken", "Chicken "), ("pizza", "Pizza "), ("sandwich", "Sandwich "),
        ("onionrings", "Onionrings "), ("milkshake", "Milkshake "), ("coke", "Coke ")]
        .iter()
        .map(|&p| (p.0.to_string(), p.1.to_string()))
        .collect();
    let mut return_string:String = String::new();
    let mut input_copy:String = input;

    for t in &master_vec {
        let mut find_elements = input_copy.find(&t.0);
        while find_elements.is_some() {
            return_string.push_str(&t.1);
            input_copy = input_copy.replacen(&t.0, "", 1);
            find_elements = input_copy.find(&t.0);
        }
    }

    return_string.trim_end().to_string()*/
}
