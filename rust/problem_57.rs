pub fn word_wrap(s: &str, k: usize) -> Option<Vec<String>> {
    let words: Vec<&str> = s.split_whitespace().collect();
    if words.is_empty() { return None; }
    let mut lines = vec![];
    let mut line = words[0].to_string();
    for w in &words[1..] {
        if line.len() + 1 + w.len() <= k { line.push(' '); line.push_str(w); }
        else { lines.push(line); line = w.to_string(); }
    }
    lines.push(line);
    if lines.iter().any(|l| l.len() > k) { return None; }
    Some(lines)
}

pub fn problem57() {
    println!("Problem 57:");
    let got = word_wrap("the quick brown fox jumps over the lazy dog", 10).unwrap();
    let exp = vec!["the quick","brown fox","jumps over","the lazy","dog"];
    assert_eq!(got, exp);
    assert!(word_wrap("toolongword", 5).is_none());
    println!("All Tests Passed");
}
