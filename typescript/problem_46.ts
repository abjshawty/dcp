export function longestPalindromicSubstring(s: string): string {
    if (!s) return "";
    let start = 0, maxLen = 1;
    function expand(l: number, r: number): void {
        while (l >= 0 && r < s.length && s[l] === s[r]) {
            if (r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            l--; r++;
        }
    }
    for (let i = 0; i < s.length; i++) { expand(i, i); expand(i, i + 1); }
    return s.slice(start, start + maxLen);
}

export function problem46(): void {
    console.log("Problem 46:");
    if (longestPalindromicSubstring("aabcdcb") !== "bcdcb") throw new Error("assertion failed");
    if (longestPalindromicSubstring("bananas") !== "anana") throw new Error("assertion failed");
    if (longestPalindromicSubstring("a")       !== "a")     throw new Error("assertion failed");
    if (longestPalindromicSubstring("cbbd")    !== "bb")    throw new Error("assertion failed");
    console.log("All Tests Passed");
}
