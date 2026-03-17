pub fn longest_increasing_subsequence(nums: &[i64]) -> usize {
    let mut tails: Vec<i64> = vec![];
    for &v in nums {
        let pos = tails.partition_point(|&t| t < v);
        if pos == tails.len() { tails.push(v); } else { tails[pos] = v; }
    }
    tails.len()
}

pub fn problem75() {
    println!("Problem 75:");
    assert_eq!(longest_increasing_subsequence(&[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]), 6);
    assert_eq!(longest_increasing_subsequence(&[1,2,3]), 3);
    assert_eq!(longest_increasing_subsequence(&[3,2,1]), 1);
    println!("All Tests Passed");
}
