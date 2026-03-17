type Board54 = number[][];

function sudokuValid(board: Board54, r: number, c: number, d: number): boolean {
    for (let i = 0; i < 9; i++) if (board[r][i] === d || board[i][c] === d) return false;
    const br = Math.floor(r/3)*3, bc = Math.floor(c/3)*3;
    for (let i = 0; i < 3; i++) for (let j = 0; j < 3; j++) if (board[br+i][bc+j] === d) return false;
    return true;
}

export function solveSudoku(board: Board54): Board54 | null {
    for (let r = 0; r < 9; r++)
        for (let c = 0; c < 9; c++) {
            if (board[r][c] !== 0) continue;
            for (let d = 1; d <= 9; d++) {
                if (sudokuValid(board, r, c, d)) {
                    board[r][c] = d;
                    if (solveSudoku(board)) return board;
                    board[r][c] = 0;
                }
            }
            return null;
        }
    return board;
}

export function problem54(): void {
    console.log("Problem 54:");
    const board: Board54 = [
        [5,3,0,0,7,0,0,0,0],[6,0,0,1,9,5,0,0,0],[0,9,8,0,0,0,0,6,0],
        [8,0,0,0,6,0,0,0,3],[4,0,0,8,0,3,0,0,1],[7,0,0,0,2,0,0,0,6],
        [0,6,0,0,0,0,2,8,0],[0,0,0,4,1,9,0,0,5],[0,0,0,0,8,0,0,7,9],
    ];
    const solved = solveSudoku(board);
    if (!solved) throw new Error("no solution");
    if (solved.some(row => row.some(v => v === 0))) throw new Error("unsolved");
    console.log("All Tests Passed");
}
