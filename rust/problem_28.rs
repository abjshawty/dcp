pub fn justify_text(words: &[&str], k: usize) -> Vec<String> {
    let mut lines: Vec<String> = Vec::new();
    let mut i = 0;
    while i < words.len() {
        let mut line_len = words[i].len();
        let mut j = i + 1;
        while j < words.len() && line_len + 1 + words[j].len() <= k {
            line_len += 1 + words[j].len();
            j += 1;
        }
        let line_words = &words[i..j];
        let gaps = j - i - 1;
        if j == words.len() || gaps == 0 {
            let line = line_words.join(" ");
            let pad = k - line.len();
            lines.push(format!("{}{}", line, " ".repeat(pad)));
        } else {
            let total_chars: usize = line_words.iter().map(|w| w.len()).sum();
            let total_spaces = k - total_chars;
            let base = total_spaces / gaps;
            let extra = total_spaces % gaps;
            let mut line = String::new();
            for (idx, w) in line_words.iter().enumerate() {
                line.push_str(w);
                if idx < gaps {
                    line.push_str(&" ".repeat(base));
                    if idx < extra { line.push(' '); }
                }
            }
            lines.push(line);
        }
        i = j;
    }
    lines
}

pub fn problem28() {
    println!("Problem 28:");
    let words = vec!["the","quick","brown","fox","jumps","over","the","lazy","dog"];
    let result = justify_text(&words, 16);
    let expected = vec!["the  quick brown", "fox  jumps  over", "the   lazy   dog"];
    assert_eq!(result, expected);
    assert!(result.iter().all(|l| l.len() == 16));
    println!("All Tests Passed");
}
