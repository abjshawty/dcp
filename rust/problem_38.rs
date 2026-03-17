pub fn n_queens(n: usize) -> usize {
    let mut cols  = vec![false; n];
    let mut diag1 = vec![false; 2 * n];
    let mut diag2 = vec![false; 2 * n];
    let mut count = 0usize;
    fn place(row: usize, n: usize, cols: &mut Vec<bool>,
             diag1: &mut Vec<bool>, diag2: &mut Vec<bool>, count: &mut usize) {
        if row == n { *count += 1; return; }
        for col in 0..n {
            let d1 = row + n - col;
            let d2 = row + col;
            if cols[col] || diag1[d1] || diag2[d2] { continue; }
            cols[col] = true; diag1[d1] = true; diag2[d2] = true;
            place(row + 1, n, cols, diag1, diag2, count);
            cols[col] = false; diag1[d1] = false; diag2[d2] = false;
        }
    }
    place(0, n, &mut cols, &mut diag1, &mut diag2, &mut count);
    count
}

pub fn problem38() {
    println!("Problem 38:");
    assert_eq!(n_queens(1),  1);
    assert_eq!(n_queens(4),  2);
    assert_eq!(n_queens(8), 92);
    println!("All Tests Passed");
}
