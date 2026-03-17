use std::collections::HashMap;

pub struct LFUCache67 {
    cap: usize,
    keys: HashMap<i32, (i32, usize)>,
    freqs: HashMap<usize, Vec<i32>>,
    min_freq: usize,
}

impl LFUCache67 {
    pub fn new(cap: usize) -> Self { LFUCache67 { cap, keys: HashMap::new(), freqs: HashMap::new(), min_freq: 0 } }
    fn touch(&mut self, key: i32) {
        let (val, freq) = *self.keys.get(&key).unwrap();
        let bucket = self.freqs.get_mut(&freq).unwrap();
        bucket.retain(|&k| k != key);
        if bucket.is_empty() { self.freqs.remove(&freq); if self.min_freq == freq { self.min_freq += 1; } }
        let new_freq = freq + 1;
        self.freqs.entry(new_freq).or_default().push(key);
        self.keys.insert(key, (val, new_freq));
    }
    pub fn get(&mut self, key: i32) -> Option<i32> {
        if !self.keys.contains_key(&key) { return None; }
        self.touch(key); Some(self.keys[&key].0)
    }
    pub fn set(&mut self, key: i32, val: i32) {
        if self.cap == 0 { return; }
        if self.keys.contains_key(&key) { self.keys.get_mut(&key).unwrap().0 = val; self.touch(key); return; }
        if self.keys.len() >= self.cap {
            let bucket = self.freqs.get_mut(&self.min_freq).unwrap();
            let evict = bucket.remove(0);
            self.keys.remove(&evict);
        }
        self.keys.insert(key, (val, 1));
        self.freqs.entry(1).or_default().push(key);
        self.min_freq = 1;
    }
}

pub fn problem67() {
    println!("Problem 67:");
    let mut c = LFUCache67::new(2);
    c.set(1,1); c.set(2,2);
    assert_eq!(c.get(1), Some(1));
    c.set(3,3);
    assert_eq!(c.get(2), None);
    assert_eq!(c.get(3), Some(3));
    println!("All Tests Passed");
}
