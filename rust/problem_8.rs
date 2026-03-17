// IntNode is a binary tree node with an integer value.
pub struct IntNode {
    pub val: i64,
    pub left: Option<Box<IntNode>>,
    pub right: Option<Box<IntNode>>,
}

impl IntNode {
    pub fn new(val: i64, left: Option<Box<IntNode>>, right: Option<Box<IntNode>>) -> Box<Self> {
        Box::new(IntNode { val, left, right })
    }
    pub fn leaf(val: i64) -> Box<Self> { Self::new(val, None, None) }
}

// count_unival_subtrees counts subtrees where every node has the same value.
// Returns (is_unival, count).
fn helper(node: &Option<Box<IntNode>>) -> (bool, usize) {
    let node = match node { Some(n) => n, None => return (true, 0) };
    let (left_unival,  left_count)  = helper(&node.left);
    let (right_unival, right_count) = helper(&node.right);
    let mut count = left_count + right_count;

    let is_unival = left_unival && right_unival
        && node.left.as_ref().map_or(true,  |n| n.val == node.val)
        && node.right.as_ref().map_or(true, |n| n.val == node.val);

    if is_unival { count += 1; }
    (is_unival, count)
}

pub fn count_unival_subtrees(root: &Option<Box<IntNode>>) -> usize {
    helper(root).1
}

pub fn problem8() {
    println!("Problem 8:");
    //       0
    //      / \
    //     1   0
    //        / \
    //       1   0
    //      / \
    //     1   1
    let root = IntNode::new(0,
        Some(IntNode::leaf(1)),
        Some(IntNode::new(0,
            Some(IntNode::new(1, Some(IntNode::leaf(1)), Some(IntNode::leaf(1)))),
            Some(IntNode::leaf(0)),
        )),
    );
    assert_eq!(count_unival_subtrees(&Some(root)), 5, "assertion failed");
    println!("All Tests Passed");
}
