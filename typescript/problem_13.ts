// longestSubstringKDistinct returns the length of the longest substring
// containing at most k distinct characters.
// Uses a sliding window with a character-frequency map.
// This runs in O(n) time and O(k) space.
export function longestSubstringKDistinct(s: string, k: number): number {
    const freq = new Map<string, number>();
    let left = 0, best = 0;

    for (let right = 0; right < s.length; right++) {
        const ch = s[right];
        freq.set(ch, (freq.get(ch) ?? 0) + 1); // expand window

        // shrink from left until at most k distinct chars remain
        while (freq.size > k) {
            const lch = s[left];
            const cnt = freq.get(lch)! - 1;
            if (cnt === 0) freq.delete(lch); else freq.set(lch, cnt);
            left++;
        }

        best = Math.max(best, right - left + 1);
    }
    return best;
}

export function problem13(): void {
    console.log("Problem 13:");
    if (longestSubstringKDistinct("abcba", 2) !== 3) throw new Error("assertion failed");
    if (longestSubstringKDistinct("aa", 1)    !== 2) throw new Error("assertion failed");
    if (longestSubstringKDistinct("abc", 3)   !== 3) throw new Error("assertion failed");
    if (longestSubstringKDistinct("", 2)      !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
