pub struct MaxStack {
    data: Vec<i64>,
    maxs: Vec<i64>,
}

impl MaxStack {
    pub fn new() -> Self { MaxStack { data: Vec::new(), maxs: Vec::new() } }

    pub fn push(&mut self, val: i64) {
        self.data.push(val);
        let m = self.maxs.last().copied().unwrap_or(i64::MIN).max(val);
        self.maxs.push(m);
    }

    pub fn pop(&mut self) -> Option<i64> {
        self.maxs.pop();
        self.data.pop()
    }

    pub fn max(&self) -> Option<i64> { self.maxs.last().copied() }
}

pub fn problem43() {
    println!("Problem 43:");
    let mut s = MaxStack::new();
    s.push(1); s.push(3); s.push(2);
    assert_eq!(s.max(), Some(3));
    assert_eq!(s.pop(), Some(2));
    assert_eq!(s.max(), Some(3));
    assert_eq!(s.pop(), Some(3));
    assert_eq!(s.max(), Some(1));
    assert_eq!(MaxStack::new().pop(), None);
    println!("All Tests Passed");
}
