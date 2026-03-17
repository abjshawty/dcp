// num_decodings counts the number of ways to decode a numeric string where
// '1'–'9' map to a–z and '10'–'26' map to j–z.
// Uses bottom-up DP: dp[i] = number of ways to decode s[i:].
// This runs in O(n) time and O(n) space.
pub fn num_decodings(s: &str) -> usize {
    let bytes = s.as_bytes();
    let n = bytes.len();
    let mut dp = vec![0usize; n + 1];
    dp[n] = 1; // empty suffix: one way

    for i in (0..n).rev() {
        if bytes[i] == b'0' { continue; } // leading zero — invalid
        dp[i] = dp[i + 1]; // single-digit decode

        // two-digit decode: valid if s[i..i+2] is between 10 and 26
        if i + 1 < n {
            let two = (bytes[i] - b'0') as usize * 10 + (bytes[i + 1] - b'0') as usize;
            if (10..=26).contains(&two) { dp[i] += dp[i + 2]; }
        }
    }
    dp[0]
}

pub fn problem7() {
    println!("Problem 7:");
    assert_eq!(num_decodings("111"), 3, "assertion failed");
    assert_eq!(num_decodings("12"),  2, "assertion failed");
    assert_eq!(num_decodings("226"), 3, "assertion failed");
    assert_eq!(num_decodings("10"),  1, "assertion failed");
    println!("All Tests Passed");
}
