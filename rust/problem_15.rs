// reservoir_sample picks one element uniformly at random from a stream.
// Uses a simple LCG for reproducibility. Runs in O(n) time and O(1) space.
pub fn reservoir_sample(stream: &[i64], seed: u64) -> i64 {
    let mut s = seed;
    let mut lcg_next = |n: u64| -> u64 {
        s = s.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
        (s >> 33) % n
    };
    let mut result = stream[0];
    for i in 1..stream.len() {
        if lcg_next(i as u64 + 1) == 0 { // probability 1/(i+1)
            result = stream[i];
        }
    }
    result
}

pub fn problem15() {
    println!("Problem 15:");
    let stream: Vec<i64> = (1..=10).collect();
    let mut counts = std::collections::HashMap::<i64, u64>::new();
    let trials: u64 = 100_000;
    for seed in 0..trials {
        let v = reservoir_sample(&stream, seed);
        *counts.entry(v).or_insert(0) += 1;
    }
    for &v in &stream {
        let freq = *counts.get(&v).unwrap_or(&0) as f64 / trials as f64;
        assert!(freq >= 0.08 && freq <= 0.12,
            "assertion failed: element {} frequency {}", v, freq);
    }
    println!("All Tests Passed");
}
