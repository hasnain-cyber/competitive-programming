use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let mut m: i64 = iter.next().unwrap().parse().unwrap();

        let mut arr: Vec<i64> = (0..n).map(|_| iter.next().unwrap().parse().unwrap()).collect();

        arr.sort();

        let mut sum = 0;
        for i in (0..n).rev() {
            if m == 0 {
                break;
            }
            sum += m * arr[i];
            m -= 1;
        }

        println!("{}", sum);
    }
}