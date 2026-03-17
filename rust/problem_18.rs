use std::collections::VecDeque;

// max_subarray_of_size_k returns the maximum value in each sliding window of size k.
// Uses a monotonic deque of indices in decreasing value order.
// This runs in O(n) time and O(k) space.
pub fn max_subarray_of_size_k(nums: &[i64], k: usize) -> Vec<i64> {
    let mut deque: VecDeque<usize> = VecDeque::new();
    let mut result = Vec::new();

    for i in 0..nums.len() {
        // remove indices outside the window
        while deque.front().map_or(false, |&f| f + k <= i) {
            deque.pop_front();
        }
        // remove smaller elements from the back
        while deque.back().map_or(false, |&b| nums[b] < nums[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
        if i + 1 >= k { result.push(nums[*deque.front().unwrap()]); }
    }
    result
}

pub fn problem18() {
    println!("Problem 18:");
    assert_eq!(max_subarray_of_size_k(&[10,5,2,7,8,7], 3), vec![10,7,8,8], "assertion failed");
    assert_eq!(max_subarray_of_size_k(&[1,2,3], 1), vec![1,2,3], "assertion failed");
    println!("All Tests Passed");
}
