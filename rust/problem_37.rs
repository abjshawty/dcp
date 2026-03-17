pub fn power_set(nums: &[i64]) -> Vec<Vec<i64>> {
    let mut result: Vec<Vec<i64>> = vec![vec![]];
    for &v in nums {
        let n = result.len();
        for i in 0..n {
            let mut sub = result[i].clone();
            sub.push(v);
            result.push(sub);
        }
    }
    result
}

pub fn problem37() {
    println!("Problem 37:");
    assert_eq!(power_set(&[1,2,3]).len(), 8);
    assert_eq!(power_set(&[]).len(),      1);
    assert_eq!(power_set(&[1]).len(),     2);
    println!("All Tests Passed");
}
