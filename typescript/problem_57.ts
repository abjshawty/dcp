export function wordWrap(s: string, k: number): string[] | null {
    const words = s.split(/\s+/).filter(Boolean);
    if (!words.length) return null;
    const lines: string[] = [];
    let line = words[0];
    for (const w of words.slice(1)) {
        if (line.length + 1 + w.length <= k) line += ' ' + w;
        else { lines.push(line); line = w; }
    }
    lines.push(line);
    if (lines.some(l => l.length > k)) return null;
    return lines;
}

export function problem57(): void {
    console.log("Problem 57:");
    if (JSON.stringify(wordWrap("the quick brown fox jumps over the lazy dog", 10)) !==
        JSON.stringify(["the quick","brown fox","jumps over","the lazy","dog"]))
        throw new Error("assertion failed");
    if (wordWrap("toolongword", 5) !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
