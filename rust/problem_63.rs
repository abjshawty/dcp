pub fn word_in_matrix(matrix: &Vec<Vec<char>>, word: &str) -> bool {
    let chars: Vec<char> = word.chars().collect();
    let n = chars.len();
    let rows = matrix.len(); let cols = matrix[0].len();
    for r in 0..rows {
        for c in 0..cols.saturating_sub(n-1) {
            if (0..n).all(|i| matrix[r][c+i] == chars[i]) { return true; }
        }
    }
    for c in 0..cols {
        for r in 0..rows.saturating_sub(n-1) {
            if (0..n).all(|i| matrix[r+i][c] == chars[i]) { return true; }
        }
    }
    false
}

pub fn problem63() {
    println!("Problem 63:");
    let m = vec![
        vec!['F','A','C','I'], vec!['O','B','Q','P'],
        vec!['A','N','O','B'], vec!['M','A','S','S'],
    ];
    assert!( word_in_matrix(&m, "FOAM"));
    assert!( word_in_matrix(&m, "MASS"));
    assert!(!word_in_matrix(&m, "NOPE"));
    println!("All Tests Passed");
}
