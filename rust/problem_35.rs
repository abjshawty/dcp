pub fn sort_rgb(arr: &mut Vec<u8>) {
    let (mut lo, mut mid, mut hi) = (0usize, 0usize, arr.len().wrapping_sub(1));
    while arr.len() > 0 && mid <= hi {
        match arr[mid] {
            b'R' => { arr.swap(lo, mid); lo += 1; mid += 1; }
            b'G' => { mid += 1; }
            _    => { arr.swap(mid, hi); if hi == 0 { break; } hi -= 1; }
        }
    }
}

pub fn problem35() {
    println!("Problem 35:");
    let mut arr = b"GBRRBRG".to_vec();
    sort_rgb(&mut arr);
    assert_eq!(arr, b"RRRGGBB".to_vec());
    let mut arr2 = b"BGR".to_vec();
    sort_rgb(&mut arr2);
    assert_eq!(arr2, b"RGB".to_vec());
    println!("All Tests Passed");
}
