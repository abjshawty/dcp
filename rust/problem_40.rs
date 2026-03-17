pub fn single_number(nums: &[i64]) -> i64 {
    let mut result = 0i64;
    for bit in 0..64 {
        let total: i64 = nums.iter().map(|&n| (n >> bit) & 1).sum();
        if total % 3 != 0 { result |= 1 << bit; }
    }
    result
}

pub fn problem40() {
    println!("Problem 40:");
    assert_eq!(single_number(&[6,1,3,3,3,6,6]),  1);
    assert_eq!(single_number(&[13,19,13,13]),    19);
    assert_eq!(single_number(&[0,0,0,5]),         5);
    println!("All Tests Passed");
}
