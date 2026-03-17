pub fn running_median(nums: &[i64]) -> Vec<f64> {
    let mut sorted: Vec<i64> = Vec::new();
    let mut result = Vec::new();
    for &v in nums {
        let pos = sorted.partition_point(|&x| x < v);
        sorted.insert(pos, v);
        let n = sorted.len();
        let median = if n % 2 == 1 {
            sorted[n / 2] as f64
        } else {
            (sorted[n / 2 - 1] + sorted[n / 2]) as f64 / 2.0
        };
        result.push(median);
    }
    result
}

pub fn problem33() {
    println!("Problem 33:");
    let got = running_median(&[2,1,5,7,2,0,5]);
    let exp = vec![2.0, 1.5, 2.0, 3.5, 2.0, 2.0, 2.0];
    assert_eq!(got, exp);
    println!("All Tests Passed");
}
