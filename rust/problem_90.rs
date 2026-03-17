use rand::Rng;
use std::collections::HashSet;

pub fn random_excluding(n: usize, exclude: &[usize]) -> usize {
    let excl: HashSet<usize> = exclude.iter().cloned().collect();
    let valid: Vec<usize> = (0..n).filter(|i| !excl.contains(i)).collect();
    valid[rand::thread_rng().gen_range(0..valid.len())]
}

pub fn problem90() {
    println!("Problem 90:");
    for _ in 0..100 { assert_eq!(random_excluding(5, &[0,1,2,4]), 3); }
    let mut counts = [0u32; 5];
    for _ in 0..1000 { counts[random_excluding(5, &[2])] += 1; }
    for &k in &[0,1,3,4] { assert!(counts[k] > 100); }
    println!("All Tests Passed");
}
