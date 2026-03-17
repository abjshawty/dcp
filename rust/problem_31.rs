pub fn edit_distance(a: &str, b: &str) -> usize {
    let a: Vec<char> = a.chars().collect();
    let b: Vec<char> = b.chars().collect();
    let (m, n) = (a.len(), b.len());
    let mut dp = vec![vec![0usize; n + 1]; m + 1];
    for i in 0..=m { dp[i][0] = i; }
    for j in 0..=n { dp[0][j] = j; }
    for i in 1..=m {
        for j in 1..=n {
            dp[i][j] = if a[i-1] == b[j-1] {
                dp[i-1][j-1]
            } else {
                1 + dp[i-1][j].min(dp[i][j-1]).min(dp[i-1][j-1])
            };
        }
    }
    dp[m][n]
}

pub fn problem31() {
    println!("Problem 31:");
    assert_eq!(edit_distance("kitten", "sitting"), 3);
    assert_eq!(edit_distance("", "abc"),            3);
    assert_eq!(edit_distance("abc", ""),            3);
    assert_eq!(edit_distance("abc", "abc"),         0);
    assert_eq!(edit_distance("a", "b"),             1);
    println!("All Tests Passed");
}
