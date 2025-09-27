use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let c: i32 = iter.next().unwrap().parse().unwrap();
        let d: i32 = iter.next().unwrap().parse().unwrap();

        if c - a < 0 || d - b < 0 {
            println!("NO");
            continue;
        }

        // Min from a and b
        let min_ab = a.min(b);
        let max_ab = a.max(b);
        if max_ab > min_ab * 2 + 2 {
            println!("NO");
            continue;
        }

        let min_cd = (c - a).min(d - b);
        let max_cd = (c - a).max(d - b);
        if max_cd > min_cd * 2 + 2 {
            println!("NO");
            continue;
        }

        println!("YES");
    }
}