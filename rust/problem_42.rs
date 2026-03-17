pub fn subset_sum(nums: &[i64], target: i64) -> Option<Vec<i64>> {
    fn bt(nums: &[i64], idx: usize, remaining: i64, current: &mut Vec<i64>) -> Option<Vec<i64>> {
        if remaining == 0 { return Some(current.clone()); }
        if idx == nums.len() || remaining < 0 { return None; }
        current.push(nums[idx]);
        if let Some(r) = bt(nums, idx + 1, remaining - nums[idx], current) { return Some(r); }
        current.pop();
        bt(nums, idx + 1, remaining, current)
    }
    bt(nums, 0, target, &mut Vec::new())
}

pub fn problem42() {
    println!("Problem 42:");
    let r1 = subset_sum(&[12,1,61,5,9,2], 24).unwrap();
    assert_eq!(r1.iter().sum::<i64>(), 24);
    assert!(subset_sum(&[1,2,3], 100).is_none());
    assert_eq!(subset_sum(&[5], 5).unwrap(), vec![5]);
    println!("All Tests Passed");
}
