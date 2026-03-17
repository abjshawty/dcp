export function isMatch(s: string, p: string): boolean {
    const m = s.length, n = p.length;
    const dp: boolean[][] = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(false));
    dp[m][n] = true;

    for (let j = n - 1; j >= 0; j--) {
        if (j + 1 < n && p[j + 1] === '*') dp[m][j] = dp[m][j + 2];
    }

    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            const firstMatch = p[j] === '.' || p[j] === s[i];
            if (j + 1 < n && p[j + 1] === '*') {
                dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
            } else {
                dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}

export function problem25(): void {
    console.log("Problem 25:");
    if (!isMatch("ray",     "ra."))  throw new Error("assertion failed");
    if ( isMatch("raymond", "ra."))  throw new Error("assertion failed");
    if (!isMatch("chat",    ".*at")) throw new Error("assertion failed");
    if ( isMatch("chats",   ".*at")) throw new Error("assertion failed");
    if (!isMatch("",        "a*"))   throw new Error("assertion failed");
    if (!isMatch("aaa",     "a*"))   throw new Error("assertion failed");
    if (!isMatch("ab",      ".*"))   throw new Error("assertion failed");
    console.log("All Tests Passed");
}
