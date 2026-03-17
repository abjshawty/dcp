fn digit_sum(mut n: u64) -> u64 { let mut s=0; while n>0 { s+=n%10; n/=10; } s }

pub fn nth_perfect_number(n: u64) -> u64 {
    let (mut count, mut num) = (0u64, 0u64);
    while count < n { num += 1; if digit_sum(num) == 10 { count += 1; } }
    num
}

pub fn problem70() {
    println!("Problem 70:");
    assert_eq!(nth_perfect_number(1), 19);
    assert_eq!(nth_perfect_number(2), 28);
    assert_eq!(nth_perfect_number(3), 37);
    println!("All Tests Passed");
}
