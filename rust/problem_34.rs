pub fn min_palindrome(s: &str) -> String {
    let s: Vec<char> = s.chars().collect();
    let n = s.len();
    let mut dp = vec![vec![0usize; n]; n];
    for len in 2..=n {
        for i in 0..=(n - len) {
            let j = i + len - 1;
            dp[i][j] = if s[i] == s[j] {
                if len == 2 { 0 } else { dp[i+1][j-1] }
            } else {
                1 + dp[i+1][j].min(dp[i][j-1])
            };
        }
    }
    fn build(s: &[char], dp: &Vec<Vec<usize>>, i: usize, j: usize) -> String {
        if i > j { return String::new(); }
        if i == j { return s[i].to_string(); }
        if s[i] == s[j] {
            return format!("{}{}{}", s[i], build(s, dp, i+1, j-1), s[j]);
        }
        let add_left  = format!("{}{}{}", s[j], build(s, dp, i, j-1), s[j]);
        let add_right = format!("{}{}{}", s[i], build(s, dp, i+1, j), s[i]);
        if dp[i+1][j] < dp[i][j-1] { return add_right; }
        if dp[i][j-1] < dp[i+1][j] { return add_left; }
        add_left.min(add_right)
    }
    build(&s, &dp, 0, n - 1)
}

pub fn problem34() {
    println!("Problem 34:");
    assert_eq!(min_palindrome("race"),   "ecarace");
    assert_eq!(min_palindrome("google"), "elgoogle");
    assert_eq!(min_palindrome("a"),      "a");
    assert_eq!(min_palindrome("ab"),     "aba");
    println!("All Tests Passed");
}
