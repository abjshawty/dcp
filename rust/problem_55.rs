use std::collections::HashMap;
use rand::Rng;

pub struct URLShortener55 {
    s2l: HashMap<String, String>,
    l2s: HashMap<String, String>,
}

impl URLShortener55 {
    pub fn new() -> Self { URLShortener55 { s2l: HashMap::new(), l2s: HashMap::new() } }
    pub fn shorten(&mut self, url: &str) -> String {
        if let Some(s) = self.l2s.get(url) { return s.clone(); }
        let short = format!("{:06x}", rand::thread_rng().gen::<u32>() & 0xFFFFFF);
        self.s2l.insert(short.clone(), url.to_string());
        self.l2s.insert(url.to_string(), short.clone());
        short
    }
    pub fn restore(&self, short: &str) -> Option<String> { self.s2l.get(short).cloned() }
}

pub fn problem55() {
    println!("Problem 55:");
    let mut us = URLShortener55::new();
    let s1 = us.shorten("https://example.com");
    assert!(!s1.is_empty());
    assert_eq!(us.restore(&s1), Some("https://example.com".to_string()));
    assert_eq!(us.shorten("https://example.com"), s1);
    assert_eq!(us.restore("notexist"), None);
    println!("All Tests Passed");
}
