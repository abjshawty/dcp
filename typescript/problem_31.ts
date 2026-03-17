export function editDistance(a: string, b: string): number {
    const m = a.length, n = b.length;
    const dp: number[][] = Array.from({ length: m + 1 }, (_, i) =>
        Array.from({ length: n + 1 }, (_, j) => (i === 0 ? j : j === 0 ? i : 0))
    );
    for (let i = 1; i <= m; i++)
        for (let j = 1; j <= n; j++)
            dp[i][j] = a[i-1] === b[j-1]
                ? dp[i-1][j-1]
                : 1 + Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
    return dp[m][n];
}

export function problem31(): void {
    console.log("Problem 31:");
    if (editDistance("kitten", "sitting") !== 3) throw new Error("assertion failed");
    if (editDistance("", "abc")           !== 3) throw new Error("assertion failed");
    if (editDistance("abc", "")           !== 3) throw new Error("assertion failed");
    if (editDistance("abc", "abc")        !== 0) throw new Error("assertion failed");
    if (editDistance("a", "b")            !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
