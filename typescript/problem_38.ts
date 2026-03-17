export function nQueens(n: number): number {
    const cols  = new Set<number>();
    const diag1 = new Set<number>();
    const diag2 = new Set<number>();
    let count = 0;
    function place(row: number): void {
        if (row === n) { count++; return; }
        for (let col = 0; col < n; col++) {
            if (cols.has(col) || diag1.has(row - col) || diag2.has(row + col)) continue;
            cols.add(col); diag1.add(row - col); diag2.add(row + col);
            place(row + 1);
            cols.delete(col); diag1.delete(row - col); diag2.delete(row + col);
        }
    }
    place(0);
    return count;
}

export function problem38(): void {
    console.log("Problem 38:");
    if (nQueens(1) !== 1)  throw new Error("assertion failed");
    if (nQueens(4) !== 2)  throw new Error("assertion failed");
    if (nQueens(8) !== 92) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
