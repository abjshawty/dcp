pub fn min_parens_removal(s: &str) -> usize {
    let (mut open, mut close) = (0usize, 0usize);
    for c in s.chars() {
        if c == '(' { open += 1; }
        else { if open > 0 { open -= 1; } else { close += 1; } }
    }
    open + close
}

pub fn problem86() {
    println!("Problem 86:");
    assert_eq!(min_parens_removal("()())()"), 1);
    assert_eq!(min_parens_removal(")("),      2);
    assert_eq!(min_parens_removal("()()"),    0);
    println!("All Tests Passed");
}
