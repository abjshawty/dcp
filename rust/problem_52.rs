use std::collections::HashMap;

pub struct LRUCache52 {
    cap: usize,
    order: Vec<i32>,
    data: HashMap<i32, i32>,
}

impl LRUCache52 {
    pub fn new(cap: usize) -> Self { LRUCache52 { cap, order: vec![], data: HashMap::new() } }
    pub fn get(&mut self, key: i32) -> Option<i32> {
        if !self.data.contains_key(&key) { return None; }
        self.order.retain(|&k| k != key);
        self.order.push(key);
        Some(*self.data.get(&key).unwrap())
    }
    pub fn set(&mut self, key: i32, val: i32) {
        if self.data.contains_key(&key) { self.order.retain(|&k| k != key); }
        else if self.order.len() >= self.cap {
            let evict = self.order.remove(0);
            self.data.remove(&evict);
        }
        self.data.insert(key, val);
        self.order.push(key);
    }
}

pub fn problem52() {
    println!("Problem 52:");
    let mut c = LRUCache52::new(2);
    c.set(1,1); c.set(2,2);
    assert_eq!(c.get(1), Some(1));
    c.set(3,3);
    assert_eq!(c.get(2), None);
    assert_eq!(c.get(3), Some(3));
    println!("All Tests Passed");
}
