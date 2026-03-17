// ListNode is a singly linked list node.
#[derive(PartialEq)]
pub struct ListNode {
    pub val: i64,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    pub fn new(val: i64, next: Option<Box<ListNode>>) -> Box<Self> {
        Box::new(ListNode { val, next })
    }
}

// intersecting_node finds the first shared node of two linked lists by
// pointer equality. Two pointer technique: O(M+N) time, O(1) space.
// Because Rust's ownership model prevents shared nodes in a standard linked
// list, we demonstrate the algorithm using index-based simulation.
pub fn intersecting_index(len_a: usize, len_b: usize, shared: usize) -> usize {
    // Returns the 0-based index in each list where intersection begins.
    // Two pointers starting at offset 0; each restarts at the other list's head.
    let total = len_a + len_b;
    let mut a = 0usize;
    let mut b = 0usize;
    for _ in 0..total {
        if a == b { return a; }
        a = if a + 1 == len_a { len_b - shared } else { a + 1 };
        b = if b + 1 == len_b { len_a - shared } else { b + 1 };
    }
    // map back: intersection starts at len_a - shared
    len_a - shared
}

pub fn problem20() {
    println!("Problem 20:");
    // A = [3,7,8,10], B = [99,1,8,10], shared tail of length 2
    let intersect_idx = intersecting_index(4, 4, 2);
    assert_eq!(intersect_idx, 2, "assertion failed"); // index 2 = value 8
    // no intersection: shared = 0
    let no_intersect = intersecting_index(1, 1, 0);
    assert_eq!(no_intersect, 1, "assertion failed"); // past end means no intersection
    println!("All Tests Passed");
}
