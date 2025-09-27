use std::io::{self, Read};
use std::collections::HashSet;

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();

        let arr: Vec<i64> = (0..n).map(|_| iter.next().unwrap().parse().unwrap()).collect();

        let mut seen = HashSet::new();
        let mut found = false;
        for &x in &arr {
            if !seen.insert(x) {
                found = true;
                break;
            }
        }

        if found {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}