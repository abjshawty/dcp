pub fn can_partition(nums: &[i64]) -> bool {
    let total: i64 = nums.iter().sum();
    if total % 2 != 0 { return false; }
    let target = (total / 2) as usize;
    let mut dp = vec![false; target + 1];
    dp[0] = true;
    for &v in nums {
        for j in (v as usize..=target).rev() { dp[j] = dp[j] || dp[j - v as usize]; }
    }
    dp[target]
}

pub fn problem60() {
    println!("Problem 60:");
    assert!( can_partition(&[15,5,20,10,35,15,10]));
    assert!(!can_partition(&[15,5,20,10,35]));
    assert!( can_partition(&[1,5,11,5]));
    println!("All Tests Passed");
}
