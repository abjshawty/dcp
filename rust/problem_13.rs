use std::collections::HashMap;

// longest_substring_k_distinct returns the length of the longest substring
// containing at most k distinct characters.
// Uses a sliding window. This runs in O(n) time and O(k) space.
pub fn longest_substring_k_distinct(s: &str, k: usize) -> usize {
    let chars: Vec<char> = s.chars().collect();
    let mut freq: HashMap<char, usize> = HashMap::new();
    let mut left = 0usize;
    let mut best = 0usize;

    for right in 0..chars.len() {
        *freq.entry(chars[right]).or_insert(0) += 1; // expand window

        // shrink from left until at most k distinct chars remain
        while freq.len() > k {
            let cnt = freq.get_mut(&chars[left]).unwrap();
            *cnt -= 1;
            if *cnt == 0 { freq.remove(&chars[left]); }
            left += 1;
        }

        best = best.max(right - left + 1);
    }
    best
}

pub fn problem13() {
    println!("Problem 13:");
    assert_eq!(longest_substring_k_distinct("abcba", 2), 3, "assertion failed");
    assert_eq!(longest_substring_k_distinct("aa", 1),    2, "assertion failed");
    assert_eq!(longest_substring_k_distinct("abc", 3),   3, "assertion failed");
    assert_eq!(longest_substring_k_distinct("", 2),      0, "assertion failed");
    println!("All Tests Passed");
}
