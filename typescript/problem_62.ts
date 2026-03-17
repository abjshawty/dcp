export function countPaths(n: number, m: number): number {
    const dp = Array.from({length: n}, () => new Array(m).fill(1));
    for (let i = 1; i < n; i++)
        for (let j = 1; j < m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[n-1][m-1];
}

export function problem62(): void {
    console.log("Problem 62:");
    if (countPaths(2,2) !== 2)  throw new Error("assertion failed");
    if (countPaths(5,5) !== 70) throw new Error("assertion failed");
    if (countPaths(1,1) !== 1)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
