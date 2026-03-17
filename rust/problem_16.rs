// OrderLog records the last N order IDs using a circular buffer.
// record and get_last both run in O(1) time and O(N) space.
pub struct OrderLog {
    buf: Vec<i64>,
    n: usize,
    pos: usize,
}

impl OrderLog {
    pub fn new(n: usize) -> Self {
        Self { buf: vec![0; n], n, pos: 0 }
    }

    pub fn record(&mut self, order_id: i64) {
        self.buf[self.pos] = order_id;
        self.pos = (self.pos + 1) % self.n;
    }

    // get_last returns the i-th last element (i=1 is most recent).
    pub fn get_last(&self, i: usize) -> i64 {
        self.buf[(self.pos + self.n - i) % self.n]
    }
}

pub fn problem16() {
    println!("Problem 16:");
    let mut log = OrderLog::new(3);
    log.record(1); log.record(2); log.record(3);
    assert_eq!(log.get_last(1), 3, "assertion failed");
    assert_eq!(log.get_last(2), 2, "assertion failed");
    assert_eq!(log.get_last(3), 1, "assertion failed");
    log.record(4);
    assert_eq!(log.get_last(1), 4, "assertion failed");
    assert_eq!(log.get_last(2), 3, "assertion failed");
    println!("All Tests Passed");
}
