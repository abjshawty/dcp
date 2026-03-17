pub struct StackQueue {
    inbox: Vec<i32>,
    outbox: Vec<i32>,
}

impl StackQueue {
    pub fn new() -> Self { StackQueue { inbox: vec![], outbox: vec![] } }
    pub fn enqueue(&mut self, v: i32) { self.inbox.push(v); }
    pub fn dequeue(&mut self) -> Option<i32> {
        if self.outbox.is_empty() {
            while let Some(v) = self.inbox.pop() { self.outbox.push(v); }
        }
        self.outbox.pop()
    }
}

pub fn problem53() {
    println!("Problem 53:");
    let mut q = StackQueue::new();
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    assert_eq!(q.dequeue(), Some(1));
    assert_eq!(q.dequeue(), Some(2));
    q.enqueue(4);
    assert_eq!(q.dequeue(), Some(3));
    assert_eq!(q.dequeue(), Some(4));
    assert_eq!(q.dequeue(), None);
    println!("All Tests Passed");
}
