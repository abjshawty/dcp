export function knightTours(n: number): number {
    const board: boolean[][] = Array.from({length:n}, () => new Array(n).fill(false));
    const moves = [[2,1],[2,-1],[-2,1],[-2,-1],[1,2],[1,-2],[-1,2],[-1,-2]];
    let count = 0;
    function dfs(r: number, c: number, visited: number): void {
        if (visited === n*n) { count++; return; }
        for (const [dr,dc] of moves) {
            const nr=r+dr, nc=c+dc;
            if (nr>=0&&nr<n&&nc>=0&&nc<n&&!board[nr][nc]) {
                board[nr][nc]=true; dfs(nr,nc,visited+1); board[nr][nc]=false;
            }
        }
    }
    for (let r=0;r<n;r++) for (let c=0;c<n;c++) { board[r][c]=true; dfs(r,c,1); board[r][c]=false; }
    return count;
}

export function problem64(): void {
    console.log("Problem 64:");
    if (knightTours(1) !== 1) throw new Error("assertion failed");
    if (knightTours(2) !== 0) throw new Error("assertion failed");
    if (knightTours(3) !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
