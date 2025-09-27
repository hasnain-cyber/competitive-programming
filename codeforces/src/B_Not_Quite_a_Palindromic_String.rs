use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let _n: usize = iter.next().unwrap().parse().unwrap();
        let k: usize = iter.next().unwrap().parse().unwrap();
        let s = iter.next().unwrap();

        let mut c_0 = s.chars().filter(|&c| c == '0').count();
        let mut c_1 = s.chars().filter(|&c| c == '1').count();
        
        let mn = c_0.min(c_1);
        let mx = c_0.max(c_1);

        let mn_pairs = (mx - mn) / 2;
        let mx_pairs = c_0 / 2 + c_1 / 2;

        if k >= mn_pairs && k <= mx_pairs && (k - mn_pairs) % 2 == 0 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}