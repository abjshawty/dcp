pub struct TreeNode80 {
    pub val: &'static str,
    pub left: Option<Box<TreeNode80>>,
    pub right: Option<Box<TreeNode80>>,
}

pub fn deepest_node(root: &Option<Box<TreeNode80>>) -> (&'static str, usize) {
    match root {
        None => ("", 0),
        Some(n) => {
            let (lv, ld) = deepest_node(&n.left);
            let (rv, rd) = deepest_node(&n.right);
            if ld > rd { (lv, ld+1) } else if rd > ld { (rv, rd+1) } else { (n.val, 1) }
        }
    }
}

pub fn problem80() {
    println!("Problem 80:");
    let root = Some(Box::new(TreeNode80 { val:"a",
        left: Some(Box::new(TreeNode80 { val:"b",
            left: Some(Box::new(TreeNode80 { val:"d", left:None, right:None })), right:None })),
        right: Some(Box::new(TreeNode80 { val:"c", left:None, right:None })),
    }));
    assert_eq!(deepest_node(&root).0, "d");
    println!("All Tests Passed");
}
