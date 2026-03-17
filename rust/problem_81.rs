use std::collections::HashMap;

pub fn phone_letters(mapping: &HashMap<char, Vec<String>>, digits: &str) -> Vec<String> {
    if digits.is_empty() { return vec![String::new()]; }
    let first = &mapping[&digits.chars().next().unwrap()];
    let rest = phone_letters(mapping, &digits[1..]);
    let mut result = vec![];
    for letter in first { for r in &rest { result.push(format!("{}{}", letter, r)); } }
    result
}

pub fn problem81() {
    println!("Problem 81:");
    let mut m = HashMap::new();
    m.insert('2', vec!["a".to_string(),"b".to_string(),"c".to_string()]);
    m.insert('3', vec!["d".to_string(),"e".to_string(),"f".to_string()]);
    let got = phone_letters(&m, "23");
    assert_eq!(got.len(), 9);
    println!("All Tests Passed");
}
