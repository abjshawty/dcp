// first_missing_positive finds the smallest positive integer absent from numbers.
// It uses the array itself as a hash map: for each value v in [1..n], it places
// v at index v-1. After rearranging, the first index i where numbers[i] != i+1
// reveals the answer i+1. This runs in O(n) time and O(1) extra space.
pub fn first_missing_positive(numbers: &mut Vec<i64>) -> i64 {
    let n = numbers.len();

    // place each value v into its "home" index v-1, if 1 <= v <= n
    for i in 0..n {
        loop {
            let v = numbers[i];
            if v < 1 || v > n as i64 || numbers[v as usize - 1] == v {
                break;
            }
            let j = v as usize - 1;
            numbers.swap(i, j); // swap into place
        }
    }

    // first index whose value is wrong reveals the missing positive
    for i in 0..n {
        if numbers[i] != i as i64 + 1 {
            return i as i64 + 1;
        }
    }

    n as i64 + 1 // all of 1..n are present
}

pub fn problem4() {
    println!("Problem 4:");
    assert_eq!(first_missing_positive(&mut vec![3, 4, -1, 1]), 2, "assertion failed");
    assert_eq!(first_missing_positive(&mut vec![1, 2, 0]),      3, "assertion failed");
    assert_eq!(first_missing_positive(&mut vec![1, 2, 3]),      4, "assertion failed");
    assert_eq!(first_missing_positive(&mut vec![7, 8, 9]),      1, "assertion failed");
    println!("All Tests Passed");
}
