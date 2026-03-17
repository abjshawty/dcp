pub fn longest_palindromic_substring(s: &str) -> String {
    let chars: Vec<char> = s.chars().collect();
    let n = chars.len();
    if n == 0 { return String::new(); }
    let (mut start, mut max_len) = (0usize, 1usize);
    let expand = |mut l: i64, mut r: i64| -> (usize, usize) {
        while l >= 0 && r < n as i64 && chars[l as usize] == chars[r as usize] { l -= 1; r += 1; }
        ((l + 1) as usize, (r - l - 1) as usize)
    };
    for i in 0..n {
        let (s1, len1) = expand(i as i64, i as i64);
        if len1 > max_len { start = s1; max_len = len1; }
        if i + 1 < n {
            let (s2, len2) = expand(i as i64, i as i64 + 1);
            if len2 > max_len { start = s2; max_len = len2; }
        }
    }
    chars[start..start+max_len].iter().collect()
}

pub fn problem46() {
    println!("Problem 46:");
    assert_eq!(longest_palindromic_substring("aabcdcb"), "bcdcb");
    assert_eq!(longest_palindromic_substring("bananas"), "anana");
    assert_eq!(longest_palindromic_substring("a"),       "a");
    assert_eq!(longest_palindromic_substring("cbbd"),    "bb");
    println!("All Tests Passed");
}
