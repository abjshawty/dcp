// XorLinkedList is an XOR doubly-linked list backed by a Vec.
// Vec indices serve as stand-in memory addresses; usize::MAX is null.

const NULL: usize = usize::MAX;

struct XorNode { val: i64, both: usize }

pub struct XorLinkedList {
    nodes: Vec<XorNode>,
    head: usize,
    tail: usize,
}

impl XorLinkedList {
    pub fn new() -> Self {
        Self { nodes: Vec::new(), head: NULL, tail: NULL }
    }

    // add appends an element to the end of the list.
    pub fn add(&mut self, val: i64) {
        let idx = self.nodes.len();
        let prev = self.tail;
        // both = prev XOR null; XOR in Rust: prev ^ NULL
        self.nodes.push(XorNode { val, both: prev ^ NULL });
        if self.tail != NULL {
            // update old tail: replace NULL with new index
            self.nodes[self.tail].both ^= NULL ^ idx;
        }
        self.tail = idx;
        if self.head == NULL { self.head = idx; }
    }

    // get returns the value at the given 0-based index.
    pub fn get(&self, index: usize) -> i64 {
        let mut prev = NULL;
        let mut curr = self.head;
        for _ in 0..index {
            let next = prev ^ self.nodes[curr].both; // XOR out prev to get next
            prev = curr;
            curr = next;
        }
        self.nodes[curr].val
    }
}

pub fn problem6() {
    println!("Problem 6:");
    let mut lst = XorLinkedList::new();
    for v in [1, 2, 3, 4] { lst.add(v); }
    assert_eq!(lst.get(0), 1, "assertion failed");
    assert_eq!(lst.get(1), 2, "assertion failed");
    assert_eq!(lst.get(2), 3, "assertion failed");
    assert_eq!(lst.get(3), 4, "assertion failed");
    println!("All Tests Passed");
}
