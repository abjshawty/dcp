use std::collections::BinaryHeap;
use std::cmp::Reverse;

type Link78 = Option<Box<ListNode78>>;
pub struct ListNode78 { pub val: i32, pub next: Link78 }

fn from_vec78(v: &[i32]) -> Link78 {
    let mut h = None;
    for &x in v.iter().rev() { let mut n = Box::new(ListNode78{val:x,next:None}); n.next=h; h=Some(n); }
    h
}
fn to_vec78(mut h: Link78) -> Vec<i32> {
    let mut r = vec![]; while let Some(n) = h { r.push(n.val); h = n.next; } r
}

pub fn merge_k_lists(mut lists: Vec<Link78>) -> Link78 {
    let mut heap: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
    for (i, l) in lists.iter().enumerate() {
        if let Some(n) = l { heap.push(Reverse((n.val, i))); }
    }
    let mut dummy = Box::new(ListNode78{val:0,next:None});
    let mut cur = &mut dummy as *mut Box<ListNode78>;
    while let Some(Reverse((_, i))) = heap.pop() {
        let node = lists[i].take().unwrap();
        lists[i] = node.next;
        if let Some(n) = &lists[i] { heap.push(Reverse((n.val, i))); }
        unsafe { (*cur).next = Some(node); cur = (*cur).next.as_mut().unwrap(); }
    }
    dummy.next
}

pub fn problem78() {
    println!("Problem 78:");
    let lists = vec![from_vec78(&[1,4,7]), from_vec78(&[2,5,8]), from_vec78(&[3,6,9])];
    assert_eq!(to_vec78(merge_k_lists(lists)), vec![1,2,3,4,5,6,7,8,9]);
    println!("All Tests Passed");
}
