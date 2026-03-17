// wordBreak reconstructs s from words using backtracking with memoisation.
// Returns any valid split, or null if impossible.
export function wordBreak(s: string, words: string[]): string[] | null {
    const wordSet = new Set(words);
    const failed = new Set<number>();

    function backtrack(start: number): string[] | null {
        if (start === s.length) return [];
        if (failed.has(start)) return null;
        for (let end = start + 1; end <= s.length; end++) {
            const word = s.slice(start, end);
            if (wordSet.has(word)) {
                const rest = backtrack(end);
                if (rest !== null) return [word, ...rest];
            }
        }
        failed.add(start);
        return null;
    }

    return backtrack(0);
}

export function problem22(): void {
    console.log("Problem 22:");
    const r1 = wordBreak("thequickbrownfox", ["quick","brown","the","fox"]);
    if (!r1 || r1.join(",") !== "the,quick,brown,fox") throw new Error("assertion failed");
    const r2 = wordBreak("bedbathandbeyond", ["bed","bath","bedbath","and","beyond"]);
    if (r2 === null) throw new Error("assertion failed");
    if (wordBreak("xyz", ["a","b"]) !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
