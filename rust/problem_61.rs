pub fn fast_pow(x: i64, y: i64) -> i64 {
    if y == 0 { return 1; }
    if y < 0  { return 0; }
    let half = fast_pow(x, y / 2);
    if y % 2 == 0 { half * half } else { half * half * x }
}

pub fn problem61() {
    println!("Problem 61:");
    assert_eq!(fast_pow(2, 10), 1024);
    assert_eq!(fast_pow(3, 0),  1);
    assert_eq!(fast_pow(5, 3),  125);
    println!("All Tests Passed");
}
