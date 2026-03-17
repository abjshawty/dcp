// Locking binary tree. Nodes are stored in a flat Vec; indices act as pointers.
// Each node tracks parent index and a count of locked descendants.
// NULL sentinel: usize::MAX.

pub struct LockTree {
    vals:              Vec<i64>,
    locked:            Vec<bool>,
    locked_desc_count: Vec<usize>,
    parent:            Vec<usize>,
    left:              Vec<usize>,
    right:             Vec<usize>,
}

impl LockTree {
    pub fn new() -> Self {
        LockTree {
            vals:              Vec::new(),
            locked:            Vec::new(),
            locked_desc_count: Vec::new(),
            parent:            Vec::new(),
            left:              Vec::new(),
            right:             Vec::new(),
        }
    }

    pub fn add_node(&mut self, val: i64, parent: usize) -> usize {
        let idx = self.vals.len();
        self.vals.push(val);
        self.locked.push(false);
        self.locked_desc_count.push(0);
        self.parent.push(parent);
        self.left.push(usize::MAX);
        self.right.push(usize::MAX);
        idx
    }

    pub fn is_locked(&self, idx: usize) -> bool { self.locked[idx] }

    fn can_lock_or_unlock(&self, idx: usize) -> bool {
        if self.locked_desc_count[idx] > 0 { return false; }
        let mut p = self.parent[idx];
        while p != usize::MAX {
            if self.locked[p] { return false; }
            p = self.parent[p];
        }
        true
    }

    pub fn lock(&mut self, idx: usize) -> bool {
        if self.locked[idx] || !self.can_lock_or_unlock(idx) { return false; }
        self.locked[idx] = true;
        let mut p = self.parent[idx];
        while p != usize::MAX { self.locked_desc_count[p] += 1; p = self.parent[p]; }
        true
    }

    pub fn unlock(&mut self, idx: usize) -> bool {
        if !self.locked[idx] || !self.can_lock_or_unlock(idx) { return false; }
        self.locked[idx] = false;
        let mut p = self.parent[idx];
        while p != usize::MAX { self.locked_desc_count[p] -= 1; p = self.parent[p]; }
        true
    }
}

pub fn problem24() {
    println!("Problem 24:");
    let mut t = LockTree::new();
    let root  = t.add_node(1, usize::MAX);
    let left  = t.add_node(2, root);
    let right = t.add_node(3, root);
    let ll    = t.add_node(4, left);
    t.left[root] = left; t.right[root] = right; t.left[left] = ll;

    assert!(t.lock(left),         "should lock left");
    assert!(t.is_locked(left),    "left should be locked");
    assert!(!t.lock(root),        "root has locked descendant");
    assert!(!t.lock(ll),          "ll has locked ancestor");
    assert!(t.unlock(left),       "should unlock left");
    assert!(!t.is_locked(left),   "left should be unlocked");
    assert!(t.lock(root),         "root should now lock");
    println!("All Tests Passed");
}
