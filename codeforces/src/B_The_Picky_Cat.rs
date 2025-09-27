use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();

        let arr: Vec<i64> = (0..n)
            .map(|_| iter.next().unwrap().parse::<i64>().unwrap().abs())
            .collect();

        let first = arr[0];
        let mut sorted = arr.clone();
        sorted.sort();

        let mid = n / 2;
        let mut found = false;
        for i in 0..=mid {
            if sorted[i] == first {
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