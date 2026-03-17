// largest_sum_non_adjacent returns the largest sum of non-adjacent elements.
// Uses O(1) space DP. This runs in O(n) time.
pub fn largest_sum_non_adjacent(nums: &[i64]) -> i64 {
    let (mut prev_prev, mut prev) = (0i64, 0i64);
    for &n in nums {
        let curr = prev.max(prev_prev + n); // skip or take
        prev_prev = prev;
        prev = curr;
    }
    prev
}

pub fn problem9() {
    println!("Problem 9:");
    assert_eq!(largest_sum_non_adjacent(&[2, 4, 6, 2, 5]), 13, "assertion failed");
    assert_eq!(largest_sum_non_adjacent(&[5, 1, 1, 5]),    10, "assertion failed");
    assert_eq!(largest_sum_non_adjacent(&[]),               0, "assertion failed");
    assert_eq!(largest_sum_non_adjacent(&[3]),              3, "assertion failed");
    println!("All Tests Passed");
}
