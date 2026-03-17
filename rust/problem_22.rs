use std::collections::{HashMap, HashSet};

// word_break reconstructs s from words using backtracking with memoisation.
// Returns any valid split or None.
pub fn word_break<'a>(s: &'a str, words: &[&str]) -> Option<Vec<String>> {
    let word_set: HashSet<&str> = words.iter().cloned().collect();
    let mut failed: HashMap<usize, bool> = HashMap::new();

    fn backtrack<'a>(
        s: &'a str,
        start: usize,
        word_set: &HashSet<&str>,
        failed: &mut HashMap<usize, bool>,
    ) -> Option<Vec<String>> {
        if start == s.len() { return Some(vec![]); }
        if *failed.get(&start).unwrap_or(&false) { return None; }
        for end in (start + 1)..=s.len() {
            let word = &s[start..end];
            if word_set.contains(word) {
                if let Some(mut rest) = backtrack(s, end, word_set, failed) {
                    rest.insert(0, word.to_string());
                    return Some(rest);
                }
            }
        }
        failed.insert(start, true);
        None
    }

    backtrack(s, 0, &word_set, &mut failed)
}

pub fn problem22() {
    println!("Problem 22:");
    let r1 = word_break("thequickbrownfox", &["quick","brown","the","fox"]);
    assert_eq!(r1.as_deref(), Some(["the","quick","brown","fox"].as_slice()), "assertion failed");
    let r2 = word_break("bedbathandbeyond", &["bed","bath","bedbath","and","beyond"]);
    assert!(r2.is_some(), "assertion failed");
    assert!(word_break("xyz", &["a","b"]).is_none(), "assertion failed");
    println!("All Tests Passed");
}
