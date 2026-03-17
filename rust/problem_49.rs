pub fn max_subarray_sum(arr: &[i64]) -> i64 {
    let (mut best, mut cur) = (0i64, 0i64);
    for &v in arr {
        cur = 0_i64.max(cur + v);
        best = best.max(cur);
    }
    best
}

pub fn problem49() {
    println!("Problem 49:");
    assert_eq!(max_subarray_sum(&[34,-50,42,14,-5,86]), 137);
    assert_eq!(max_subarray_sum(&[-5,-1,-8,-9]),         0);
    assert_eq!(max_subarray_sum(&[1,2,3]),               6);
    println!("All Tests Passed");
}
