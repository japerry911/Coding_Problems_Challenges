fn main() {
    let a = [1, 2, 3];
    println!("{:?}", a);
    let doubled:Vec<i32> = a.iter().map(|&x| x * 2).collect();
    println!("{:?}", doubled);
}
