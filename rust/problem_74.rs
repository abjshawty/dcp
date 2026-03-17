pub fn count_in_mult_table(n: u64, x: u64) -> u64 {
    (1..=n).filter(|&i| x % i == 0 && x / i <= n).count() as u64
}

pub fn problem74() {
    println!("Problem 74:");
    assert_eq!(count_in_mult_table(6, 12), 4);
    assert_eq!(count_in_mult_table(3, 6),  2);
    assert_eq!(count_in_mult_table(1, 1),  1);
    println!("All Tests Passed");
}
