pub fn count_inversions(arr: &[i64]) -> i64 {
    fn merge_sort(a: Vec<i64>) -> (Vec<i64>, i64) {
        if a.len() <= 1 { return (a, 0); }
        let mid = a.len() / 2;
        let (left, lc) = merge_sort(a[..mid].to_vec());
        let (right, rc) = merge_sort(a[mid..].to_vec());
        let mut merged = Vec::with_capacity(a.len());
        let (mut i, mut j, mut mc) = (0, 0, 0i64);
        while i < left.len() && j < right.len() {
            if left[i] <= right[j] { merged.push(left[i]); i += 1; }
            else { merged.push(right[j]); mc += (left.len() - i) as i64; j += 1; }
        }
        merged.extend_from_slice(&left[i..]);
        merged.extend_from_slice(&right[j..]);
        (merged, lc + rc + mc)
    }
    merge_sort(arr.to_vec()).1
}

pub fn problem44() {
    println!("Problem 44:");
    assert_eq!(count_inversions(&[2,4,1,3,5]), 3);
    assert_eq!(count_inversions(&[5,4,3,2,1]), 10);
    assert_eq!(count_inversions(&[1,2,3]),     0);
    println!("All Tests Passed");
}
