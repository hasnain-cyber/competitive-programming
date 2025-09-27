use std::io::{self, Read};
use std::collections::BinaryHeap;

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let arr: Vec<i64> = (0..n).map(|_| iter.next().unwrap().parse().unwrap()).collect();

        let mut pq = BinaryHeap::from(arr);
        let mut sum = 0;

        while pq.len() > 1 {
            let first = pq.pop().unwrap();
            let second = pq.pop().unwrap();
            sum += first.max(second);
        }

        if let Some(last) = pq.pop() {
            sum += last;
        }

        println!("{}", sum);
    }
}