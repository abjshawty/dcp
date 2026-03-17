export function minPalindrome(s: string): string {
    const n = s.length;
    const dp: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));
    for (let len = 2; len <= n; len++)
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            dp[i][j] = s[i] === s[j] ? dp[i+1][j-1] : 1 + Math.min(dp[i+1][j], dp[i][j-1]);
        }
    function build(i: number, j: number): string {
        if (i > j) return '';
        if (i === j) return s[i];
        if (s[i] === s[j]) return s[i] + build(i+1, j-1) + s[j];
        const addLeft  = s[j] + build(i, j-1) + s[j];
        const addRight = s[i] + build(i+1, j) + s[i];
        if (dp[i+1][j] < dp[i][j-1]) return addRight;
        if (dp[i][j-1] < dp[i+1][j]) return addLeft;
        return addLeft < addRight ? addLeft : addRight;
    }
    return build(0, n - 1);
}

export function problem34(): void {
    console.log("Problem 34:");
    if (minPalindrome("race")   !== "ecarace")  throw new Error("assertion failed");
    if (minPalindrome("google") !== "elgoogle") throw new Error("assertion failed");
    if (minPalindrome("a")      !== "a")        throw new Error("assertion failed");
    if (minPalindrome("ab")     !== "aba")      throw new Error("assertion failed");
    console.log("All Tests Passed");
}
