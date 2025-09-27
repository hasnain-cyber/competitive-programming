use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let s = iter.next().unwrap();

        // Find the index of the last non-zero digit
        let last_nonzero = s.rfind(|c| c != '0').unwrap_or(0);

        // Count zeros after the last non-zero digit
        let zeros_after = s[last_nonzero + 1..].chars().filter(|&c| c == '0').count();

        // Count non-zeros before the last non-zero digit
        let nonzeros_before = s[..last_nonzero].chars().filter(|&c| c != '0').count();

        println!("{}", zeros_after + nonzeros_before);
    }
}