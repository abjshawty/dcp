// numDecodings counts the number of ways to decode a numeric string where
// '1'–'9' map to a–z and '10'–'26' map to j–z.
// Uses bottom-up DP: dp[i] = number of ways to decode s[i:].
// This runs in O(n) time and O(n) space.
export function numDecodings(s: string): number {
    const n = s.length;
    const dp = new Array<number>(n + 1).fill(0);
    dp[n] = 1; // empty suffix: one way

    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === '0') { dp[i] = 0; continue; } // leading zero — invalid
        dp[i] = dp[i + 1]; // single-digit decode

        // two-digit decode: valid if s[i:i+2] is between 10 and 26
        if (i + 1 < n) {
            const two = parseInt(s.slice(i, i + 2), 10);
            if (two >= 10 && two <= 26) dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}

export function problem7(): void {
    console.log("Problem 7:");
    if (numDecodings("111") !== 3) throw new Error("assertion failed");
    if (numDecodings("12")  !== 2) throw new Error("assertion failed");
    if (numDecodings("226") !== 3) throw new Error("assertion failed");
    if (numDecodings("10")  !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
