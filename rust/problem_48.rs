#[derive(Debug)]
pub struct TreeNode48 {
    pub val: String,
    pub left: Option<Box<TreeNode48>>,
    pub right: Option<Box<TreeNode48>>,
}

pub fn build_tree(preorder: &[&str], inorder: &[&str]) -> Option<Box<TreeNode48>> {
    if preorder.is_empty() { return None; }
    let root_val = preorder[0];
    let idx = inorder.iter().position(|&v| v == root_val).unwrap();
    Some(Box::new(TreeNode48 {
        val: root_val.to_string(),
        left:  build_tree(&preorder[1..1+idx], &inorder[..idx]),
        right: build_tree(&preorder[1+idx..], &inorder[idx+1..]),
    }))
}

fn inorder48(root: &Option<Box<TreeNode48>>, out: &mut Vec<String>) {
    if let Some(n) = root { inorder48(&n.left, out); out.push(n.val.clone()); inorder48(&n.right, out); }
}

pub fn problem48() {
    println!("Problem 48:");
    let pre = vec!["a","b","d","e","c","f","g"];
    let ino = vec!["d","b","e","a","f","c","g"];
    let root = build_tree(&pre, &ino);
    let mut out = vec![];
    inorder48(&root, &mut out);
    let exp: Vec<String> = ino.iter().map(|s| s.to_string()).collect();
    assert_eq!(out, exp);
    println!("All Tests Passed");
}
