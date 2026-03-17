export function minParensRemoval(s: string): number {
    let open = 0, close = 0;
    for (const c of s) {
        if (c === '(') open++;
        else { if (open > 0) open--; else close++; }
    }
    return open + close;
}

export function problem86(): void {
    console.log("Problem 86:");
    if (minParensRemoval("()())()") !== 1) throw new Error("assertion failed");
    if (minParensRemoval(")(")      !== 2) throw new Error("assertion failed");
    if (minParensRemoval("()()")    !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
