// Remove kth-last element using index-based singly linked list (Vec-backed).
pub struct SLList {
    vals:  Vec<i64>,
    nexts: Vec<usize>, // usize::MAX = null
}

impl SLList {
    pub fn from_slice(slice: &[i64]) -> (Self, usize) {
        let mut l = SLList { vals: Vec::new(), nexts: Vec::new() };
        if slice.is_empty() { return (l, usize::MAX); }
        let mut head = usize::MAX;
        for &v in slice.iter().rev() {
            let idx = l.vals.len();
            l.vals.push(v);
            l.nexts.push(head);
            head = idx;
        }
        (l, head)
    }

    pub fn to_vec(&self, head: usize) -> Vec<i64> {
        let mut out = Vec::new();
        let mut cur = head;
        while cur != usize::MAX { out.push(self.vals[cur]); cur = self.nexts[cur]; }
        out
    }

    // remove_kth_last: two-pointer, one pass. Returns new head.
    pub fn remove_kth_last(&mut self, head: usize, k: usize) -> usize {
        // Build dummy node
        let dummy = self.vals.len();
        self.vals.push(0);
        self.nexts.push(head);

        let mut fast = dummy;
        let mut slow = dummy;
        for _ in 0..=k { fast = self.nexts[fast]; }
        while fast != usize::MAX { fast = self.nexts[fast]; slow = self.nexts[slow]; }
        let to_remove = self.nexts[slow];
        self.nexts[slow] = self.nexts[to_remove];
        self.nexts[dummy] // new head
    }
}

pub fn problem26() {
    println!("Problem 26:");
    let (mut l1, h1) = SLList::from_slice(&[1,2,3,4,5]);
    let h1 = l1.remove_kth_last(h1, 2);
    assert_eq!(l1.to_vec(h1), vec![1,2,3,5]);

    let (mut l2, h2) = SLList::from_slice(&[1,2,3]);
    let h2 = l2.remove_kth_last(h2, 1);
    assert_eq!(l2.to_vec(h2), vec![1,2]);

    let (mut l3, h3) = SLList::from_slice(&[1,2]);
    let h3 = l3.remove_kth_last(h3, 2);
    assert_eq!(l3.to_vec(h3), vec![2]);

    println!("All Tests Passed");
}
