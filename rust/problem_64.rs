pub fn knight_tours(n: usize) -> usize {
    let mut board = vec![vec![false; n]; n];
    let moves: &[(i64,i64)] = &[(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)];
    let mut count = 0;
    fn dfs(r: i64, c: i64, visited: usize, n: usize, board: &mut Vec<Vec<bool>>, moves: &[(i64,i64)], count: &mut usize) {
        if visited == n*n { *count += 1; return; }
        for &(dr, dc) in moves {
            let (nr, nc) = (r+dr, c+dc);
            if nr>=0 && nr<n as i64 && nc>=0 && nc<n as i64 && !board[nr as usize][nc as usize] {
                board[nr as usize][nc as usize] = true;
                dfs(nr, nc, visited+1, n, board, moves, count);
                board[nr as usize][nc as usize] = false;
            }
        }
    }
    for r in 0..n { for c in 0..n {
        board[r][c] = true;
        dfs(r as i64, c as i64, 1, n, &mut board, moves, &mut count);
        board[r][c] = false;
    } }
    count
}

pub fn problem64() {
    println!("Problem 64:");
    assert_eq!(knight_tours(1), 1);
    assert_eq!(knight_tours(2), 0);
    assert_eq!(knight_tours(3), 0);
    println!("All Tests Passed");
}
