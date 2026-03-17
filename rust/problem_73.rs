type Link73 = Option<Box<ListNode73>>;

pub struct ListNode73 { pub val: i32, pub next: Link73 }

impl ListNode73 {
    pub fn new(v: i32) -> Self { ListNode73 { val: v, next: None } }
}

pub fn reverse_list(mut head: Link73) -> Link73 {
    let mut prev = None;
    while let Some(mut node) = head {
        head = node.next.take();
        node.next = prev;
        prev = Some(node);
    }
    prev
}

fn from_vec(v: &[i32]) -> Link73 {
    let mut head = None;
    for &x in v.iter().rev() { let mut n = Box::new(ListNode73::new(x)); n.next = head; head = Some(n); }
    head
}

fn to_vec(mut h: &Link73) -> Vec<i32> {
    let mut r = vec![];
    while let Some(n) = h { r.push(n.val); h = &n.next; }
    r
}

pub fn problem73() {
    println!("Problem 73:");
    assert_eq!(to_vec(&reverse_list(from_vec(&[1,2,3,4,5]))), vec![5,4,3,2,1]);
    assert_eq!(to_vec(&reverse_list(from_vec(&[1]))), vec![1]);
    assert!(reverse_list(None).is_none());
    println!("All Tests Passed");
}
