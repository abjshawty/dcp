pub fn is_match(s: &str, p: &str) -> bool {
    let s: Vec<char> = s.chars().collect();
    let p: Vec<char> = p.chars().collect();
    let m = s.len();
    let n = p.len();
    let mut dp = vec![vec![false; n + 1]; m + 1];
    dp[m][n] = true;

    for j in (0..n).rev() {
        if j + 1 < n && p[j + 1] == '*' {
            dp[m][j] = dp[m][j + 2];
        }
    }

    for i in (0..m).rev() {
        for j in (0..n).rev() {
            let first_match = p[j] == '.' || p[j] == s[i];
            if j + 1 < n && p[j + 1] == '*' {
                dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
            } else {
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
    }
    dp[0][0]
}

pub fn problem25() {
    println!("Problem 25:");
    assert!( is_match("ray",     "ra."),  "assertion failed");
    assert!(!is_match("raymond", "ra."),  "assertion failed");
    assert!( is_match("chat",    ".*at"), "assertion failed");
    assert!(!is_match("chats",   ".*at"), "assertion failed");
    assert!( is_match("",        "a*"),   "assertion failed");
    assert!( is_match("aaa",     "a*"),   "assertion failed");
    assert!( is_match("ab",      ".*"),   "assertion failed");
    println!("All Tests Passed");
}
