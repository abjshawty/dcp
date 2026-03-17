pub fn int_divide(mut a: u64, b: u64) -> u64 {
    let mut q = 0;
    while a >= b { a -= b; q += 1; }
    q
}

pub fn problem88() {
    println!("Problem 88:");
    assert_eq!(int_divide(10, 3),   3);
    assert_eq!(int_divide(7,  2),   3);
    assert_eq!(int_divide(100, 10), 10);
    assert_eq!(int_divide(1,  1),   1);
    println!("All Tests Passed");
}
