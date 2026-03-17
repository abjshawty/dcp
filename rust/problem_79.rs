pub fn can_be_non_decreasing(nums: &[i64]) -> bool {
    let mut a = nums.to_vec();
    let mut modified = false;
    for i in 1..a.len() {
        if a[i] < a[i-1] {
            if modified { return false; }
            modified = true;
            if i >= 2 && a[i] < a[i-2] { a[i] = a[i-1]; } else { a[i-1] = a[i]; }
        }
    }
    true
}

pub fn problem79() {
    println!("Problem 79:");
    assert!( can_be_non_decreasing(&[10,5,7]));
    assert!(!can_be_non_decreasing(&[10,5,1]));
    assert!( can_be_non_decreasing(&[1,2,3]));
    println!("All Tests Passed");
}
