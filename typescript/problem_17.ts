// longestFilePath returns the character length of the longest absolute
// path to a file in the encoded filesystem string.
// Uses a depth-indexed stack of cumulative path lengths.
// This runs in O(n) time and O(d) space where d is the max depth.
export function longestFilePath(input: string): number {
    const lines = input.split("\n");
    const stack: number[] = [0]; // stack[depth] = cumulative length up to parent
    let best = 0;

    for (const line of lines) {
        let depth = 0;
        while (line[depth] === "\t") depth++;
        const name = line.slice(depth);
        const pathLen = stack[depth] + name.length;
        stack[depth + 1] = pathLen + 1; // +1 for '/'

        if (name.includes(".")) best = Math.max(best, pathLen);
    }
    return best;
}

export function problem17(): void {
    console.log("Problem 17:");
    const fs = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    if (longestFilePath(fs) !== 32) throw new Error("assertion failed");
    if (longestFilePath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") !== 20) throw new Error("assertion failed");
    if (longestFilePath("a") !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
