pub fn min_columns_to_remove(rows: &[&str]) -> usize {
    if rows.is_empty() { return 0; }
    let cols = rows[0].len();
    let row_bytes: Vec<&[u8]> = rows.iter().map(|s| s.as_bytes()).collect();
    (0..cols).filter(|&c| (1..rows.len()).any(|r| row_bytes[r][c] < row_bytes[r-1][c])).count()
}

pub fn problem76() {
    println!("Problem 76:");
    assert_eq!(min_columns_to_remove(&["cba","daf","ghi"]), 1);
    assert_eq!(min_columns_to_remove(&["abcdef"]),           0);
    assert_eq!(min_columns_to_remove(&["zyx","wvu","tsr"]), 3);
    println!("All Tests Passed");
}
