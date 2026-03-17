use std::collections::HashMap;

fn simple_hash(s: &str) -> u64 {
    s.bytes().fold(0u64, |h, b| h.wrapping_mul(31).wrapping_add(b as u64))
}

pub struct FileSyncer59 { pub files: HashMap<String, String> }

impl FileSyncer59 {
    pub fn new() -> Self { FileSyncer59 { files: HashMap::new() } }
    pub fn put(&mut self, name: &str, content: &str) { self.files.insert(name.to_string(), content.to_string()); }
    fn checksum(&self, name: &str) -> u64 { simple_hash(self.files.get(name).map(|s| s.as_str()).unwrap_or("")) }
    pub fn sync_from(&mut self, other: &FileSyncer59) -> Vec<String> {
        let mut transferred = vec![];
        for (name, content) in &other.files {
            if self.checksum(name) != other.checksum(name) {
                self.files.insert(name.clone(), content.clone());
                transferred.push(name.clone());
            }
        }
        transferred
    }
}

pub fn problem59() {
    println!("Problem 59:");
    let mut a = FileSyncer59::new(); let mut b = FileSyncer59::new();
    a.put("foo.txt", "hello world"); a.put("bar.txt", "same content");
    b.put("bar.txt", "same content");
    let mut changed = b.sync_from(&a);
    changed.sort();
    assert_eq!(changed, vec!["foo.txt"]);
    assert_eq!(b.files.get("foo.txt").unwrap(), "hello world");
    println!("All Tests Passed");
}
