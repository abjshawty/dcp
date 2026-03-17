type Link83 = Option<Box<TreeNode83>>;
pub struct TreeNode83 { pub val: i32, pub left: Link83, pub right: Link83 }

pub fn invert_tree(root: Link83) -> Link83 {
    root.map(|mut n| { n.left = invert_tree(n.right.take()); n.right = invert_tree(n.left.take()); Box::new(*n) })
}

pub fn invert_tree_fixed(root: Link83) -> Link83 {
    match root {
        None => None,
        Some(mut n) => {
            let left = invert_tree_fixed(n.left.take());
            let right = invert_tree_fixed(n.right.take());
            n.left = right; n.right = left; Some(n)
        }
    }
}

fn inorder83(root: &Link83, out: &mut Vec<i32>) {
    if let Some(n) = root { inorder83(&n.left, out); out.push(n.val); inorder83(&n.right, out); }
}

fn node83(v: i32, l: Link83, r: Link83) -> Link83 { Some(Box::new(TreeNode83{val:v,left:l,right:r})) }

pub fn problem83() {
    println!("Problem 83:");
    let root = node83(4, node83(2, node83(1,None,None), node83(3,None,None)), node83(7, node83(6,None,None), node83(9,None,None)));
    let inverted = invert_tree_fixed(root);
    let mut out = vec![];
    inorder83(&inverted, &mut out);
    assert_eq!(out, vec![9,7,6,4,3,2,1]);
    println!("All Tests Passed");
}
