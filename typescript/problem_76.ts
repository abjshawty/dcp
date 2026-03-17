export function minColumnsToRemove(rows: string[]): number {
    if (!rows.length) return 0;
    let remove = 0;
    for (let c = 0; c < rows[0].length; c++)
        for (let r = 1; r < rows.length; r++)
            if (rows[r][c] < rows[r-1][c]) { remove++; break; }
    return remove;
}

export function problem76(): void {
    console.log("Problem 76:");
    if (minColumnsToRemove(["cba","daf","ghi"]) !== 1) throw new Error("assertion failed");
    if (minColumnsToRemove(["abcdef"])           !== 0) throw new Error("assertion failed");
    if (minColumnsToRemove(["zyx","wvu","tsr"])  !== 3) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
