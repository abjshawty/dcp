use std::collections::HashSet;

// find_pair_with_sum checks if any two numbers in the slice sum to k.
// It uses a HashSet to track numbers seen so far. For each number n,
// it checks if the complement (k-n) was already seen — if so, a valid
// pair exists. This runs in O(n) time and O(n) space.
pub fn find_pair_with_sum(numbers: &[i64], k: i64) -> bool {
    let mut seen = HashSet::new();
    for &n in numbers {
        if seen.contains(&(k - n)) { // check if the complement was seen earlier
            return true;
        }
        seen.insert(n); // record this number for future iterations
    }
    false
}

pub fn problem1() {
    println!("Problem 1:");
    assert!(find_pair_with_sum(&[10, 15, 3, 7], 17),   "assertion failed");
    assert!(!find_pair_with_sum(&[10, 15, 3, 7], 100), "assertion failed");
    println!("All Tests Passed");
}
