// Node is a binary tree node with a string value and left/right children.
pub struct Node {
    pub val:   String,
    pub left:  Option<Box<Node>>,
    pub right: Option<Box<Node>>,
}

impl Node {
    pub fn new(val: &str, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Box<Node> {
        Box::new(Node { val: val.to_string(), left, right })
    }
}

// serialize encodes a binary tree into a comma-separated string using
// pre-order traversal. Null nodes are represented with the sentinel "#".
pub fn serialize(root: &Option<Box<Node>>) -> String {
    match root {
        None => "#".to_string(),
        Some(node) => {
            // pre-order: root, left subtree, right subtree
            format!("{},{},{}", node.val, serialize(&node.left), serialize(&node.right))
        }
    }
}

// deserialize reconstructs a binary tree from a string produced by serialize.
// It consumes tokens from a shared index, mirroring the pre-order encoding.
fn deserialize_tokens(tokens: &[&str], idx: &mut usize) -> Option<Box<Node>> {
    let val = tokens[*idx];
    *idx += 1;
    if val == "#" { // sentinel marks a null node
        return None;
    }
    // reconstruct pre-order: node first, then left and right subtrees
    let left  = deserialize_tokens(tokens, idx);
    let right = deserialize_tokens(tokens, idx);
    Some(Node::new(val, left, right))
}

pub fn deserialize(s: &str) -> Option<Box<Node>> {
    let tokens: Vec<&str> = s.split(',').collect();
    let mut idx = 0;
    deserialize_tokens(&tokens, &mut idx)
}

pub fn problem3() {
    println!("Problem 3:");
    let node = Node::new("root",
        Some(Node::new("left", Some(Node::new("left.left", None, None)), None)),
        Some(Node::new("right", None, None)));
    let result = deserialize(&serialize(&Some(node)));
    assert_eq!(
        result.as_ref().unwrap().left.as_ref().unwrap().left.as_ref().unwrap().val,
        "left.left",
        "assertion failed"
    );
    println!("All Tests Passed");
}
