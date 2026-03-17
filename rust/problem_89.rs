type Link89 = Option<Box<TreeNode89>>;
pub struct TreeNode89 { pub val: i64, pub left: Link89, pub right: Link89 }

pub fn is_valid_bst(root: &Link89, lo: i64, hi: i64) -> bool {
    match root {
        None => true,
        Some(n) => n.val > lo && n.val < hi && is_valid_bst(&n.left, lo, n.val) && is_valid_bst(&n.right, n.val, hi),
    }
}

fn node89(v: i64, l: Link89, r: Link89) -> Link89 { Some(Box::new(TreeNode89{val:v,left:l,right:r})) }

pub fn problem89() {
    println!("Problem 89:");
    let valid = node89(5, node89(3, node89(2,None,None), node89(4,None,None)), node89(7, node89(6,None,None), node89(8,None,None)));
    let invalid = node89(5, node89(3,None,None), node89(4,None,None));
    assert!( is_valid_bst(&valid,   i64::MIN, i64::MAX));
    assert!(!is_valid_bst(&invalid, i64::MIN, i64::MAX));
    println!("All Tests Passed");
}
