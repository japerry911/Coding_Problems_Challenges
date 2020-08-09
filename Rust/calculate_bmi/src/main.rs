/*
---Calculate BMI---
Write function bmi that calculates body mass index (bmi = weight / height ^ 2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"
 */

fn main() {
    println!("{}", bmi(50, 1.80));
}

fn bmi(weight: u32, height: f32) -> &'static str {
    let bmi = weight as f32 / height.powf(2.0);

    match bmi {
        _ if (bmi <= 18.5) => "Underweight",
        _ if (bmi <= 25.0) => "Normal",
        _ if (bmi <= 30.0) => "Overweight",
        _ => "Obese"
    }
}