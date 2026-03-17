pub fn select_by_bit(x: i64, y: i64, b: i64) -> i64 { x * b + y * (1 - b) }

pub fn problem85() {
    println!("Problem 85:");
    assert_eq!(select_by_bit(10, 20, 1), 10);
    assert_eq!(select_by_bit(10, 20, 0), 20);
    assert_eq!(select_by_bit(5,   7, 1),  5);
    println!("All Tests Passed");
}
