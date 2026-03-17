pub fn count_paths(n: usize, m: usize) -> u64 {
    let mut dp = vec![vec![1u64; m]; n];
    for i in 1..n { for j in 1..m { dp[i][j] = dp[i-1][j] + dp[i][j-1]; } }
    dp[n-1][m-1]
}

pub fn problem62() {
    println!("Problem 62:");
    assert_eq!(count_paths(2,2), 2);
    assert_eq!(count_paths(5,5), 70);
    assert_eq!(count_paths(1,1), 1);
    println!("All Tests Passed");
}
