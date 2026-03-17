pub struct BSTNode36 {
    pub val:   i64,
    pub left:  Option<Box<BSTNode36>>,
    pub right: Option<Box<BSTNode36>>,
}

impl BSTNode36 {
    pub fn new(val: i64, left: Option<Box<BSTNode36>>, right: Option<Box<BSTNode36>>) -> Box<Self> {
        Box::new(BSTNode36 { val, left, right })
    }
    pub fn leaf(val: i64) -> Box<Self> { Self::new(val, None, None) }
}

pub fn second_largest(root: &BSTNode36) -> i64 {
    let mut parent: Option<&BSTNode36> = None;
    let mut curr = root;
    while let Some(r) = curr.right.as_deref() {
        parent = Some(curr);
        curr = r;
    }
    if let Some(left) = curr.left.as_deref() {
        let mut node = left;
        while let Some(r) = node.right.as_deref() { node = r; }
        return node.val;
    }
    parent.unwrap().val
}

pub fn problem36() {
    println!("Problem 36:");
    let root = BSTNode36::new(5,
        Some(BSTNode36::new(3, Some(BSTNode36::leaf(2)), Some(BSTNode36::leaf(4)))),
        Some(BSTNode36::new(7, Some(BSTNode36::leaf(6)), Some(BSTNode36::leaf(8)))),
    );
    assert_eq!(second_largest(&root), 7);
    let root2 = BSTNode36::new(3, None,
        Some(BSTNode36::new(4, None, Some(BSTNode36::leaf(5)))));
    assert_eq!(second_largest(&root2), 4);
    let root3 = BSTNode36::new(5,
        Some(BSTNode36::new(3, None, Some(BSTNode36::leaf(4)))), None);
    assert_eq!(second_largest(&root3), 4);
    println!("All Tests Passed");
}
