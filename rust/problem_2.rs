// product_of_array_except_self returns a vec where each element is the product
// of all other elements in the input. Two passes: prefix then suffix.
// This runs in O(n) time and O(n) space without using division.
pub fn product_of_array_except_self(numbers: &[i64]) -> Vec<i64> {
    let n = numbers.len();
    let mut result = vec![0i64; n];

    // first pass: result[i] = product of all elements to the left of i
    result[0] = 1;
    for i in 1..n {
        result[i] = result[i - 1] * numbers[i - 1];
    }

    // second pass: multiply in the product of all elements to the right of i
    let mut suffix = 1i64;
    for i in (0..n).rev() {
        result[i] *= suffix;
        suffix *= numbers[i];
    }

    result
}

pub fn problem2() {
    println!("Problem 2:");
    let result   = product_of_array_except_self(&[1, 2, 3, 4, 5]);
    let expected = [120, 60, 40, 30, 24];
    for (i, &exp) in expected.iter().enumerate() {
        assert_eq!(result[i], exp, "assertion failed");
    }
    println!("All Tests Passed");
}
