use std::io::{self, Read};

fn main() {
    // Read all input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let arr: Vec<i64> = (0..n).map(|_| iter.next().unwrap().parse().unwrap()).collect();

        // Precompute greatest_left array
        let mut greatest_left = vec![arr[0]; n];
        for i in 1..n {
            greatest_left[i] = greatest_left[i - 1].max(arr[i - 1]);
        }

        let mut result = vec![0; n];
        let mut suffix_sum = 0;

        for i in (0..n).rev() {
            suffix_sum += arr[i];
            if i > 0 && arr[i] < greatest_left[i] {
                result[i] = suffix_sum - arr[i] + greatest_left[i];
            } else {
                result[i] = suffix_sum;
            }
        }

        result.reverse();
        println!("{}", result.iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" "));
    }
}