pub fn search_rotated(arr: &[i64], target: i64) -> Option<usize> {
    let (mut lo, mut hi) = (0i64, arr.len() as i64 - 1);
    while lo <= hi {
        let mid = ((lo + hi) / 2) as usize;
        if arr[mid] == target { return Some(mid); }
        if arr[lo as usize] <= arr[mid] {
            if arr[lo as usize] <= target && target < arr[mid] { hi = mid as i64 - 1; }
            else { lo = mid as i64 + 1; }
        } else {
            if arr[mid] < target && target <= arr[hi as usize] { lo = mid as i64 + 1; }
            else { hi = mid as i64 - 1; }
        }
    }
    None
}

pub fn problem58() {
    println!("Problem 58:");
    assert_eq!(search_rotated(&[13,18,25,2,8,10], 8),  Some(4));
    assert_eq!(search_rotated(&[13,18,25,2,8,10], 13), Some(0));
    assert_eq!(search_rotated(&[13,18,25,2,8,10], 99), None);
    println!("All Tests Passed");
}
