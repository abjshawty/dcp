pub fn rle_encode(s: &str) -> String {
    if s.is_empty() { return String::new(); }
    let chars: Vec<char> = s.chars().collect();
    let mut result = String::new();
    let mut count = 1usize;
    for i in 1..chars.len() {
        if chars[i] == chars[i - 1] {
            count += 1;
        } else {
            result.push_str(&count.to_string());
            result.push(chars[i - 1]);
            count = 1;
        }
    }
    result.push_str(&count.to_string());
    result.push(*chars.last().unwrap());
    result
}

pub fn rle_decode(s: &str) -> String {
    let chars: Vec<char> = s.chars().collect();
    let mut result = String::new();
    let mut i = 0;
    while i < chars.len() {
        let mut j = i;
        while j < chars.len() && chars[j].is_ascii_digit() { j += 1; }
        let count: usize = chars[i..j].iter().collect::<String>().parse().unwrap();
        let ch = chars[j];
        for _ in 0..count { result.push(ch); }
        i = j + 1;
    }
    result
}

pub fn problem29() {
    println!("Problem 29:");
    assert_eq!(rle_encode("AAAABBBCCDAA"), "4A3B2C1D2A");
    assert_eq!(rle_decode("4A3B2C1D2A"),  "AAAABBBCCDAA");
    assert_eq!(rle_encode("A"),           "1A");
    assert_eq!(rle_decode("1A"),          "A");
    assert_eq!(rle_encode(""),            "");
    println!("All Tests Passed");
}
