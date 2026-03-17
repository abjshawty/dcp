fn sudoku_valid(board: &[[u8;9];9], r: usize, c: usize, d: u8) -> bool {
    for i in 0..9 {
        if board[r][i] == d || board[i][c] == d { return false; }
    }
    let (br, bc) = ((r/3)*3, (c/3)*3);
    for i in 0..3 { for j in 0..3 { if board[br+i][bc+j] == d { return false; } } }
    true
}

pub fn solve_sudoku(board: &mut [[u8;9];9]) -> bool {
    for r in 0..9 { for c in 0..9 {
        if board[r][c] == 0 {
            for d in 1..=9 {
                if sudoku_valid(board, r, c, d) {
                    board[r][c] = d;
                    if solve_sudoku(board) { return true; }
                    board[r][c] = 0;
                }
            }
            return false;
        }
    } }
    true
}

pub fn problem54() {
    println!("Problem 54:");
    let mut board: [[u8;9];9] = [
        [5,3,0,0,7,0,0,0,0],[6,0,0,1,9,5,0,0,0],[0,9,8,0,0,0,0,6,0],
        [8,0,0,0,6,0,0,0,3],[4,0,0,8,0,3,0,0,1],[7,0,0,0,2,0,0,0,6],
        [0,6,0,0,0,0,2,8,0],[0,0,0,4,1,9,0,0,5],[0,0,0,0,8,0,0,7,9],
    ];
    assert!(solve_sudoku(&mut board));
    assert!(board.iter().all(|row| row.iter().all(|&v| v != 0)));
    println!("All Tests Passed");
}
