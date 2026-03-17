pub struct Reader82 { content: String, pos: usize, buf: String }

impl Reader82 {
    pub fn new(content: &str) -> Self { Reader82 { content: content.to_string(), pos: 0, buf: String::new() } }
    fn read7(&mut self) -> String {
        let end = (self.pos + 7).min(self.content.len());
        let s = self.content[self.pos..end].to_string();
        self.pos = end; s
    }
    pub fn read_n(&mut self, n: usize) -> String {
        while self.buf.len() < n { let c = self.read7(); if c.is_empty() { break; } self.buf.push_str(&c); }
        let result = self.buf[..n.min(self.buf.len())].to_string();
        self.buf = self.buf[result.len()..].to_string();
        result
    }
}

pub fn problem82() {
    println!("Problem 82:");
    let mut r = Reader82::new("Hello world");
    assert_eq!(r.read_n(5), "Hello");
    assert_eq!(r.read_n(1), " ");
    assert_eq!(r.read_n(5), "world");
    assert_eq!(r.read_n(5), "");
    println!("All Tests Passed");
}
